const obj = {
  a: 1,
  b: 2
}
console.log(obj, typeof(obj)) 
// => {a: 1, b: 2} object

const json = JSON.stringify(obj)
console.log(json, typeof(json)) 
// => {"a":1,"b":2} string

const parsed = JSON.parse(json)
console.log(parsed, typeof(parsed)) 
// => {a: 1, b: 2} object