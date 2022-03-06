package cpp.openapi;

import org.openapitools.codegen.*;
import io.swagger.models.properties.*;
import org.openapitools.codegen.languages.AbstractCppCodegen;
import org.openapitools.codegen.meta.features.*;

import io.swagger.v3.oas.models.media.Schema;
import org.openapitools.codegen.utils.ModelUtils;
import org.openapitools.codegen.utils.StringUtils;

import java.util.*;
import java.io.File;

public class CppOpenapiGenerator extends CppModifiedBaseGenerator implements CodegenConfig {

  // source folder where to write the files
  protected String sourceFolder = "src";
  protected String apiVersion = "1.0.0";

  /**
   * Configures the type of generator.
   *
   * @return  the CodegenType for this generator
   * @see     org.openapitools.codegen.CodegenType
   */
  public CodegenType getTag() {
    return CodegenType.OTHER;
  }

  /**
   * Configures a friendly name for the generator.  This will be used by the generator
   * to select the library with the -g flag.
   *
   * @return the friendly name for the generator
   */
  public String getName() {
    return "cpp-openapi";
  }

  /**
   * Provides an opportunity to inspect and modify operation data before the code is generated.
   */
  // @SuppressWarnings("unchecked")
  // @Override
  // public Map<String, Object> postProcessOperationsWithModels(Map<String, Object> objs, List<Object> allModels) {

  //   // to try debugging your code generator:
  //   // set a break point on the next line.
  //   // then debug the JUnit test called LaunchGeneratorInDebugger

  //   Map<String, Object> results = super.postProcessOperationsWithModels(objs, allModels);

  //   Map<String, Object> ops = (Map<String, Object>)results.get("operations");
  //   ArrayList<CodegenOperation> opList = (ArrayList<CodegenOperation>)ops.get("operation");

  //   // iterate over the operation and perhaps modify something
  //   for(CodegenOperation co : opList){
  //     // example:
  //     // co.httpMethod = co.httpMethod.toLowerCase();
  //   }

  //   return results;
  // }

  /**
   * Returns human-friendly help for the generator.  Provide the consumer with help
   * tips, parameters here
   *
   * @return A string value for the help message
   */
  public String getHelp() {
    return "Generates a cpp-openapi client library.";
  }

  public CppOpenapiGenerator() {
    super();

    // features
    modifyFeatureSet(feature -> feature
      .excludeGlobalFeatures(
              GlobalFeature.XMLStructureDefinitions,
              GlobalFeature.Callbacks,
              GlobalFeature.LinkObjects,
              GlobalFeature.ParameterStyling,
              GlobalFeature.MultiServer)
      .excludeSchemaSupportFeatures(
              SchemaSupportFeature.Polymorphism
      )
      .excludeParameterFeatures(
              ParameterFeature.Cookie,
              ParameterFeature.Header,
              ParameterFeature.FormUnencoded,
              ParameterFeature.FormMultipart,
              ParameterFeature.Query
      )
      .excludeDataTypeFeatures(
              DataTypeFeature.Enum,
              DataTypeFeature.Maps,
              DataTypeFeature.MapOfCollectionOfEnum,
              DataTypeFeature.MapOfCollectionOfModel,
              DataTypeFeature.MapOfCollectionOfPrimitives,
              DataTypeFeature.MapOfEnum,
              DataTypeFeature.MapOfModel

      )
      .excludeWireFormatFeatures(
              WireFormatFeature.XML,
              WireFormatFeature.PROTOBUF,
              WireFormatFeature.Custom
      ));


    // set the output folder here
    outputFolder = "generated-code/cpp-openapi";

    /**
     * Template Location.  This is the location which templates will be read from.  The generator
     * will use the resource stream to attempt to read the templates.
     */
    templateDir = "cpp-openapi";

    /**
     * Api Package.  Optional, if needed, this can be used in templates
     */
    apiPackage = "api";

    /**
     * Model Package.  Optional, if needed, this can be used in templates
     */
    modelPackage = "model";
    
    String commonPkg = "common";

    // common header
    supportingFiles.add(new SupportingFile("common/json_h.mustache",   
      sourceFolder + File.separator + commonPkg,              
      "common_json.h")
    );
    supportingFiles.add(new SupportingFile("common/common_cpp.mustache",   
      sourceFolder + File.separator + commonPkg,              
      "common.cpp")
    );

    supportingFiles.add(new SupportingFile("common/cmake.mustache",   // the input template or file
      sourceFolder + File.separator + commonPkg,              // the destination folder, relative `outputFolder`
      "CMakeLists.txt")                                          // the output file
    );

    /**
     * Models.  You can write model files using the modelTemplateFiles map.
     * if you want to create one template for file, you can do so here.
     * for multiple files for model, just put another entry in the `modelTemplateFiles` with
     * a different extension
     */
    modelTemplateFiles.put(
      "model/model_h.mustache", // the template to use
      ".h");       // the extension for each file to write

    modelTemplateFiles.put(
      "model/model_cpp.mustache", // the template to use
      ".cpp");       // the extension for each file to write

    modelTemplateFiles.put(
      "model/model_test_cpp.mustache", // the template to use
      "_test.cpp");       // the extension for each file to write

    // model cmake file
    supportingFiles.add(new SupportingFile("model/model_cmake_txt.mustache",   // the input template or file
      sourceFolder + File.separator + modelPackage,              // the destination folder, relative `outputFolder`
      "CMakeLists.txt")                                          // the output file
    );

    // lib cmake file
    supportingFiles.add(new SupportingFile("lib_cmake_txt.mustache",   // the input template or file
      sourceFolder,              // the destination folder, relative `outputFolder`
      "CMakeLists.txt")                                          // the output file
    );

    /**
     * Api classes.  You can write classes for each Api file with the apiTemplateFiles map.
     * as with models, add multiple entries with different extensions for multiple files per
     * class
     */
    // one openapi spec tag will be turn in to one file
    // all operations inside will be accessable here
    apiTemplateFiles.put(
      "api/tag_h.mustache",   // the template to use
      ".h");       // the extension for each file to write
    apiTemplateFiles.put(
      "api/tag_cpp.mustache",   // the template to use
      ".cpp");       // the extension for each file to write 
    supportingFiles.add(new SupportingFile("api/cmake.mustache", 
      sourceFolder + File.separator + apiPackage, 
      "CMakeLists.txt")
    );

    // server templates
    apiTemplateFiles.put(
      "apiServer/http_handler_h.mustache",
      ".h");
    apiTemplateFiles.put(
      "apiServer/http_handler_cpp.mustache",
      ".cpp");
    supportingFiles.add(new SupportingFile("apiServer/server_handler_h.mustache", 
      sourceFolder + File.separator + "apiServer", 
      "server_handler.h")
    );
    supportingFiles.add(new SupportingFile("apiServer/server_handler_cpp.mustache", 
      sourceFolder + File.separator + "apiServer", 
      "server_handler.cpp")
    );
    supportingFiles.add(new SupportingFile("apiServer/cmake.mustache", 
      sourceFolder + File.separator + "apiServer", 
      "CMakeLists.txt")
    );
    
    /**
     * Reserved words.  Override this with reserved words specific to your language
     */
    reservedWords = new HashSet<String> (
      Arrays.asList(
        "sample1",  // replace with static values
        "sample2")
    );

    /**
     * Additional Properties.  These values can be passed to the templates and
     * are available in models, apis, and supporting files
     */
    additionalProperties.put("apiVersion", apiVersion);

    /**
     * Supporting Files.  You can write single files for the generator with the
     * entire object tree available.  If the input file has a suffix of `.mustache
     * it will be processed by the template engine.  Otherwise, it will be copied
     */
    supportingFiles.add(new SupportingFile("myFile.mustache",   // the input template or file
      "",                                                       // the destination folder, relative `outputFolder`
      "myFile.sample")                                          // the output file
    );

    /**
     * Language Specific Primitives.  These types will not trigger imports by
     * the client generator
     */
    languageSpecificPrimitives = new HashSet<String>(
      Arrays.asList(
        "int",      // replace these with your types
        "bool")
    );

    makeTypeMappings();
  }

  private void makeTypeMappings() {
    // Types
    String cpp_array_type = "std::vector";
    String cpp_string_type = "openapi::string_t";
    String cpp_int_type = "int";
    typeMapping = new HashMap<>();

    typeMapping.put("string", cpp_string_type);
    typeMapping.put("integer", cpp_int_type);
    typeMapping.put("float", "float");
    typeMapping.put("long", cpp_int_type); // if int is marked as int64. TODO: handle int64_t
    typeMapping.put("boolean", "bool");
    typeMapping.put("double", "double");
    typeMapping.put("array", cpp_array_type);
    typeMapping.put("set", cpp_array_type); // unique array
    typeMapping.put("number", cpp_int_type);
    typeMapping.put("binary", cpp_string_type);
    typeMapping.put("password", cpp_string_type);
    typeMapping.put("file", cpp_string_type);
    typeMapping.put("DateTime", cpp_string_type);
    typeMapping.put("Date", cpp_string_type);
    typeMapping.put("UUID", cpp_string_type);
    typeMapping.put("URI", cpp_string_type);
    typeMapping.put("Map", cpp_string_type); // hack. Skip additional properties case
    typeMapping.put("Object", cpp_string_type); // hack. make inline object to string
  }

  @Override
  public String apiFilename(String templateName, String tag) {
    String suffix = apiTemplateFiles().get(templateName);
    // server api
    if (templateName.contains("apiServer")){
      return outputFolder + "/" + sourceFolder + "/" + "apiServer" + File.separator + toApiFilename(tag) + suffix;
    }
    // client api
    return apiFileFolder() + File.separator + toApiFilename(tag) + suffix;
  }
  
  @Override
  public String toModelImport(String name) {
      // use mapped type first
      String typeName = name;
      if(typeMapping.containsKey(typeName))
      {
        typeName = typeMapping.get(typeName);
      }

      // TODO find where object is from
      String[] skipTypes = new String[]{"int", "openapi::string_t", "bool", "float" , "Object"};

      if (Arrays.asList(skipTypes).contains(typeName)){
        return null;
      }
      if(typeName.equals("std::vector")){
        return "#include <vector>";
      }

      return "#include \"" + name + ".h\"";
  }

  @Override
    public String toInstantiationType(Schema p) {
        if (ModelUtils.isArraySchema(p)) {
            return instantiationTypes.get("array");
        } else {
            return null;
        }
    }

    // @Override
    // public String getTypeDeclaration(Schema p) {
    //     String openAPIType = getSchemaType(p);
    //     //if (languageSpecificPrimitives.contains(openAPIType)) {
    //         return toModelName(openAPIType);
    //     //} else {
    //     //    return openAPIType;
    //     //}
    // }

    @Override
    public String getSchemaType(Schema p) {
        String openAPIType = super.getSchemaType(p);
        String type = null;
        if (typeMapping.containsKey(openAPIType)) {
            type = typeMapping.get(openAPIType);
            if (languageSpecificPrimitives.contains(type)) {
                return toModelName(type);
            }
        } else {
            type = openAPIType;
        }
        return toModelName(type);
    }

    @Override
    public String toModelName(String type) {
        if (typeMapping.keySet().contains(type) ||
                typeMapping.values().contains(type) ||
                defaultIncludes.contains(type) ||
                languageSpecificPrimitives.contains(type)) {
            return type;
        } else {
            return StringUtils.camelize(type, false);
            // return Character.toUpperCase(type.charAt(0)) + type.substring(1);
        }
    }

    // cpp code gen mess up the casing?
    // @Override
    // public String getTypeDeclaration(String name) {
    //     return name;
    // }

    @Override
    public String toVarName(String name) {
        return StringUtils.underscore(super.toVarName(name));
    }

    // @Override
    // public String toModelImport(String name) {
    //     if (name.equals("std::string")) {
    //         return "#include <string>";
    //     } else if (name.equals("std::list")) {
    //         return "#include <list>";
    //     } else if (name.equals("Map")) {
    //         return "#include <map>";
    //     }
    //     return "#include \"" + name + ".h\"";
    // }

    // @SuppressWarnings("rawtypes")
    // @Override
    // public CodegenProperty fromProperty(String name, Schema p) {
    //   // cpp abstract class has bug    TODO:
    //   return super.fromProperty(name, p);
    // }

  /**
   * Escapes a reserved word as defined in the `reservedWords` array. Handle escaping
   * those terms here.  This logic is only called if a variable matches the reserved words
   *
   * @return the escaped term
   */
  @Override
  public String escapeReservedWord(String name) {
    return "_" + name;  // add an underscore to the name
  }

  /**
   * Location to write model files.  You can use the modelPackage() as defined when the class is
   * instantiated
   */
  public String modelFileFolder() {
    return outputFolder + "/" + sourceFolder + "/" + modelPackage().replace('.', File.separatorChar);
  }

  /**
   * Location to write api files.  You can use the apiPackage() as defined when the class is
   * instantiated
   */
  @Override
  public String apiFileFolder() {
    return outputFolder + "/" + sourceFolder + "/" + apiPackage().replace('.', File.separatorChar);
  }

  /**
   * override with any special text escaping logic to handle unsafe
   * characters so as to avoid code injection
   *
   * @param input String to be cleaned up
   * @return string with unsafe characters removed or escaped
   */
  @Override
  public String escapeUnsafeCharacters(String input) {
    //TODO: check that this logic is safe to escape unsafe characters to avoid code injection
    return input;
  }

  /**
   * Escape single and/or double quote to avoid code injection
   *
   * @param input String to be cleaned up
   * @return string with quotation mark removed or escaped
   */
  public String escapeQuotationMark(String input) {
    //TODO: check that this logic is safe to escape quotation mark to avoid code injection
    return input.replace("\"", "\\\"");
  }
}