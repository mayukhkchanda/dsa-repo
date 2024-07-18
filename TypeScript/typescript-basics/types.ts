const date = Date.now(); // TS infers type of date as Date(hover over variable to see)

class Superhero{

}

const Batman = new Superhero(); // type infered is Superhero

// Batman.name // is not allowed as name property does not exist in Superhero class