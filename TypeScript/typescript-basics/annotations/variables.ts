// type annotation: explicitly specifying the type of a variable in TS

//type annotation on different types of variables

    // primitives
        let age : number = 23;
        let Name : string = "Dua Lipa";
        let isSingle : boolean = false;

        // type and value is same
        let nullValue : null = null;  
        let undefinedValue : undefined = undefined;

    // built-in objects
        let today : Date = new Date();
    
    // arrays of primitives
        let months : string[] = ['Jan', 'Feb', 'Mar']
    
    // Classes
        class Cars {}
        let dzire : Cars = new Cars() ;

    // Object literals
        let point : {x : number, y: number} = { x : 20, y: 10}    

    // Functions
        let sum : (num1 : number, num2 : number) => number = (num1 : number, num2 : number) => (num1+num2) ;

// Use Type Annotation is majorly in below cases:

  // 1. a function that returns 'any' type value
    let response = '{"x":10,"y":20}'; 
    let parsedResponse  = JSON.parse(response); // parsedResponse has an infered type of 'any' as JSON.parse colud return 'any' type of variable
    // parsedResponse.abcd // no error given & type checking property is lost

    // Instead do:
     let parsedResponseAnnoted: {x : number, y: number} = JSON.parse(response); 
    //  parsedResponseAnnoted.abcd // type checking is present & error shown

  // 2. variable declaration & initialization are done on different lines
    let initializedLater; // type inference cannot work here 
    initializedLater = false; // as such the type safety is lost
    initializedLater = 10;

    // Instead dp
    let initializedLaterAnnoted : boolean;
    initializedLaterAnnoted = false;
    // initializedLaterAnnoted = 10;  // type checking occures here

  // 3. variable whose type cannot be infered at time of declaration 
    let nums = [-10, 0, 10]
    let numAboveZero = false ;
    // numAboveZero = nums.find( n => n > 0) // will not work 

    // Instead do:
    let numAboveZeroAnnoted : boolean | number = false;
    numAboveZeroAnnoted = nums.find( n => n > 0) // will work 

