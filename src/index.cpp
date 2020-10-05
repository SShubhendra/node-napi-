#include <napi.h>
#include <string>
#include "greeting.h"
#include <iostream>
#include "foo.h"

Napi::String foocall(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    std::string str = info[1].ToString().Utf8Value();
    char *input = new char[str.length() + 1];
    strcpy(input, str.c_str());
    Napi::Number num = info[0].ToNumber();
    foo(num, input);

    // return new `Napi::String` value
    return Napi::String::New(env, str);
}
// native C++ function that is assigned to `greetHello` property on `exports` object
Napi::String greetHello(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    // call `helloUser` function from `greeting.cpp` file
    std::string user = (std::string)info[0].ToString();
    std::string result = helloUser(user);

    // return new `Napi::String` value
    return Napi::String::New(env, result);
}

Napi::Value echoCheck(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    //     Isolate* isolate = info.GetIsolate();
    //   Local<Context> context = env->GetCurrentContext();

    //   Local<Object> obj = Object::New(isolate);
    //   obj->Set(context,
    //            String::NewFromUtf8(isolate,
    //                                "msg").ToLocalChecked(),
    //                                args[0]->ToString(context).ToLocalChecked())
    //            .FromJust();

    //   info.GetReturnValue().Set(obj);
    Napi::Array jsNativeObj = Napi::Array::New(env);

    std::string str = info[0].ToString().Utf8Value();
    // std::string str1 = info[1].ToString().Utf8Value();
    char *input = new char[str.length() + 1];
    strcpy(input, str.c_str());
    // do stuff
    // delete [] cstr;
    //     const char *input1 = info[0].ToString().Utf8Value().c_str();
    //     char *input = input1;
    char *output = (char *)info[1].ToString().Utf8Value().c_str();
    // std::cout << "\n initialinp :" << *input << "\n"
    //           << input;
    // std::cout << "\n initial output :" << output << "\n"
    //           << output;
    std::string result = echo(&input, &output);
    //std::string out = output;

    //inputs
    // Napi::Object arg0 = info[0].As<Napi::Object>();
    // Napi::Object arg1 = info[1].As<Napi::Object>();
    // Napi::Object json = env.Global().Get("JSON").As<Napi::Object>();
    // Napi::Function stringify = json.Get("stringify").As<Napi::Function>();
    // std::string arginp0 = stringify.Call(json, {arg0}).As<Napi::String>();
    // std::string arginp1 = stringify.Call(json, {arg1}).As<Napi::String>();
    // std::cout << "\n arg 0 :"
    //           << arginp0;
    // std::cout << "\n arg 1 :" << arginp1 << "\n";

    // std::cout << "\n res inputval2 :" << input << "\n"
    //           << input;
    // std::cout << "\n res output2 :" << *output << "\n"
    //           << output;

    // return new `Napi::String` value
    // for (int i = 0; i < 2; i++)
    // {
    //     jsNativeObj.Set(i, output);
    // }
    int i = 0;
    jsNativeObj.Set(i, output);
    jsNativeObj.Set(i + 1, result);
    return jsNativeObj;
    // return Napi::String ::New(env, result);
}

// Napi::Value echocmdTestNode(const Napi::CallbackInfo &info)
// {
//     Napi::Env env = info.Env();
//     Napi::Array jsNativeObj = Napi::Array::New(env);
//     std::string str0 = info[0].ToString().Utf8Value();
//     char inp0[450];
//     strcpy(inp0, str0.c_str());
//     /// std::string inp0 = (std::string)info[0].ToString();

//     std::string str = info[1].ToString().Utf8Value();
//     char *input = new char[str.length() + 1];
//     strcpy(input, str.c_str());
//     echocmdTest(inp0, (u_int8_t **)input);
//     int i = 0;
//     jsNativeObj.Set(i, inp0);
//     jsNativeObj.Set(i + 1, input);
//     return jsNativeObj;
//     //return Napi::String::New(env, result);
// }
// callback method when module is registered with Node.js
Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(
        Napi::String ::New(env, "foocall"), // property name => "greetHello"
        Napi::Function::New(env, foocall)   // property value => `greetHello` function
    );

    // exports.Set(
    //     Napi::String ::New(env, "echocmdTestNode"), // property name => "greetHello"
    //     Napi::Function::New(env, echocmdTestNode)   // property value => `greetHello` function
    // );
    // set a key on `exports` object
    exports.Set(
        Napi::String ::New(env, "echoCheck"), // property name => "greetHello"
        Napi::Function::New(env, echoCheck)   // property value => `greetHello` function
    );

    exports.Set(
        Napi::String::New(env, "greetHello"), // property name => "greetHello"
        Napi::Function::New(env, greetHello)  // property value => `greetHello` function
    );
    // return `exports` object (always)
    return exports;
}

// register `greet` module which calls `Init` method
NODE_API_MODULE(greet, Init)
