// typescript cannot infer the type of arguments sent to a function and should always be annoted.
// however, the return type can be infered but we must not rely 100% on it
const add = (x: number, y: number) : number => {
    return (x+y);
}

// function declarations
function divied(a: number, b:number) : number{
    return a/b;
}

//anonymous function declarations
const multiply = function (a: number, b:number) : number{
    return a*b;
}

//'void' return types
const logger = (message: string) : void => {
    console.log('[INFO] '+message);
    // functions with void return type can return null or undefined
    // return null; // this is allowed
}

//anontating objects in functions | try changing the type annotation for any param below and error will be shown
const nominee = {
    movie : 'Jocker',
    actor : 'Heath Ledger'
}

//Method #1
const giveOscars = function(winner:{movie:string, actor: string }){
    console.log(`The Oscar goes to ${winner.actor} for the movie ${winner.movie}!!!`);
}

//Method #2: destructing the object
const giveOscars2 = function({movie, actor}: {movie:string, actor: string } ){
    console.log(`The Oscar goes to ${actor} for the movie ${movie}!!!`);
}

giveOscars(nominee);
giveOscars2(nominee);

//annotations in objects
const player = {
    _name: 'Ezio Au Ditore',
    _age: 45,
    setAge(age:number) : void{
        this._age = age; 
    },
    getAge() : void{
        return this._age;
    },
    setName(name:String){
        this._name = name;
    },
    getName():string{
        return this._name
    },
    goodbye(): string{
        return 'Requiescat in pace';
    }
}

// player.setName(true); // not allowed and wil give error

const {_name, _age} : {_name: String; _age:Number} = player;
const {goodbye} = player;
