// 1. URIを指定する(後述のオプションを指定しない場合はGETリクエストが送信される)
fetch('http://localhost:5000')
  // 2. レスポンスを受け取った際の処理の定義
  .then(response => {
    if (response.ok) {
      return response.text()
    } else {
      throw new Error()
    }
  })
  .then(text => console.log(text)) // 3. レスポンスを正常にテキストに変換できた際の処理の定義
  .catch(error => console.error(error)) // 4. レスポンスがエラーであった場合の処理の定義