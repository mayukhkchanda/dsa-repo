//multi-dimensional typed array
const multiDimenArr = [[1,2,3],[4,5,6]];

//type restricting an empty array
const stringArr : string[] = []
  // Benifits
  // - can only hold string values
    stringArr.push('max');
    //   stringArr.push(false) //gives error 
  // - helps with type inference when accessing values
    const val = stringArr[0]; // type infered is a string
  // - can helps us during array fucntions like map, filter, reduce
    const mapped = stringArr.map( (str : String) : String => {
        return str.toUpperCase();
    } )
  // - arrays with flexible types
    const flexiArr : (String | Number)[] = [];
    flexiArr.push('1');
    flexiArr.push(2);
    // flexiArr.push(false);  // while string & number type values are allowed; any other type is not allowed
    