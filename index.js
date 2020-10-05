// import native addon
const addonGreet = require('bindings')('greet');
let a = {};
let b = {
    c: 1
};
console.log(addonGreet)
let d = addonGreet.echoCheck("eeee", a)
console.log(addonGreet.greetHello("abcd"))
console.log(d)
// console.log(addonGreet.echocmdTestNode("dddd", 555))
console.log(addonGreet.foocall("dddd", 555))


// a = b
// console.log(a)
// expose module API
exports.hello = addonGreet.greetHello;

