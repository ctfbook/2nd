// 1. XMLHttpRequestオブジェクトの作成
const xhr = new XMLHttpRequest()

// 2. URIの指定とGETリクエストの指定
xhr.open('GET', 'http://localhost:5000/test')

// 3. レスポンスを受け取った際に呼び出される関数(コールバック関数)の設定
xhr.onload = () => {
  if (xhr.status === 200) {
    console.log("[200 OK]", xhr.responseText)
  } else {
    console.log("[ERROR]", xhr.statusText)
  }
}

// 4. リクエストの送信
xhr.send()