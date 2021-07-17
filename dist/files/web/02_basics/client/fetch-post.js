// ヘッダーの設定
// メッセージボディーに含まれるエンティティがJSONであることを示す
const headers = {
  'Content-Type': 'application/json'
}
const method = 'POST' // メソッドの設定
const body = JSON.stringify({ // メッセージボディーの設定
  ctf: 'book'
})

fetch('http://localhost:5000', { headers, method, body })
  .then(response => {
    if (response.ok) {
      return response.text()
    } else {
      throw new Error()
    }
  })
  .then(text => console.log(text))
  .catch(error => console.error(error))