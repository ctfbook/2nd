const array = [100, 200, 300] // 配列の初期化
console.log(array) 
// => [100, 200, 300]

array[1] = 150 // 添字による配列へのアクセス
console.log(array) 
// => [100, 150, 300]

// オブジェクトの初期化
const obj = {
  a: 1,
  b: 2
}

obj.c = 3 // ドット(.)によるオブジェクトへのアクセス
obj['d'] = 4 // 角括弧([])によるオブジェクトへのアクセス
console.log(obj) 
// => {a: 1, b: 2, c: 3, d: 4}