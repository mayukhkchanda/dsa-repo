// typescript cannot infer the type of arguments sent to a function and should always be annoted.
// however, the return type can be infered but we must not rely 100% on it
var add = function (x, y) {
    return (x + y);
};
// function declarations
function divied(a, b) {
    return a / b;
}
//anonymous function declarations
var multiply = function (a, b) {
    return a * b;
};
//'void' return types
var logger = function (message) {
    console.log('[INFO] ' + message);
    // functions with void return type can return null or undefined
    // return null; // this is allowed
};
//anontating objects in functions
var nominee = {
    movie: 'Jocker',
    actor: 'Heath Ledger'
};
//Method #1
var giveOscars = function (winner) {
    console.log("The Oscar goes to ".concat(winner.actor, " for the movie ").concat(winner.movie, "!!!"));
};
//Method #2: destructing the object
var giveOscars2 = function (_a) {
    var movie = _a.movie, actor = _a.actor;
    console.log("The Oscar goes to ".concat(actor, " for the movie ").concat(movie, "!!!"));
};
giveOscars(nominee);
giveOscars2(nominee);
