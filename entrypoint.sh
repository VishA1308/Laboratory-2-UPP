#!/bin/bash

# Создаем HTML с логами
generate_html() {
  echo "<!DOCTYPE html>
<html>
<head>
  <title>App Logs</title>
  <meta http-equiv=\"refresh\" content=\"5\">
  <style>
    body { font-family: Arial; margin: 20px; }
    pre { background: #f4f4f4; padding: 10px; }
  </style>
</head>
<body>
  <h1>Application Logs</h1>
  <pre>$(cat /usr/share/nginx/html/app.log | sed 's/</\&lt;/g; s/>/\&gt;/g')</pre>
</body>
</html>"
}

# Обновляем логи каждые 5 секунд
while true; do
  #docker logs  lab_upprpo-app-1
  docker logs  lab_upprpo-app-1 > /usr/share/nginx/html/app.log
  generate_html > /usr/share/nginx/html/index.html
  sleep 5
done &

exec nginx -g 'daemon off;'

