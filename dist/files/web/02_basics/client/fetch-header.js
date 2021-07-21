// ヘッダーの設定
const headers = {
  'MY_HEADER': 'CTF_IS_FUN'
}

fetch('http://localhost:5000', { headers })
  .then(response => {
    if (response.ok) {
      return response.text()
    } else {
      throw new Error()
    }
  })
  .then(text => console.log(text))
  .catch(error => console.error(error))