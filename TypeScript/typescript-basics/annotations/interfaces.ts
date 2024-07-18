//interfaces helps us create Abstract Data Types(ADTs) using other data types
//and functions.
interface Employee{
    name: String,
    empId: Number,
    onProbation: boolean,
    salary: Number,
    joiningDt: Date,
    profileHdr() : string; 
}

const creditSal = (emp : Employee) : void => {
    console.log(`Hi, ${emp.name}, your salary $ ${emp.salary} for ${new Date().getMonth()} ${new Date().getFullYear()} is credited to your account.`)
}

const ceo = {
    name : 'Mark',
    empId: 1,
    onProbation: false,
    salary: 350000,
    joiningDt: new Date(),
    profileHdr() : string{
        return `I am the CEO! BITCH!`
    }
}

creditSal(ceo);