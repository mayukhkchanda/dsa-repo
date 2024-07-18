//tuples donot exist in javascript
//but typescript provides us that faciliy

//imagine, there's a csv record of users that contain data
//in a specific order: (id,name,salary) in that order
//we can create a tuple for it.

const user1 : [Number, String, Number] = [190998, 'Mad Max', 30000]

//using type alias
type User = [Number, String, Number]
const user2 : User = [190997, 'Master Cheif', 50000] 


