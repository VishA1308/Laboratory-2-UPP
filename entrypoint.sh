#!/bin/bash


generate_html() {
  echo "<!DOCTYPE html>
<html>
<head>
  <title>App Logs</title>
  <meta http-equiv="refresh" content="5">
  <style>
    body { font-family: Arial; margin: 20px; }
    pre { background: #f4f4f4; padding: 10px; }
  </style>
</head>
<body>
  <h1>Application Logs</h1>
  <pre>$(cat /usr/share/nginx/html/app.log | sed 's/</&lt;/g; s/>/&gt;/g')</pre>
</body>
</html>"
}

echo test
while true; do
  
  # Получаем логи из пода и сохраняем их в файл
  kubectl logs deployment/app-upp > /usr/share/nginx/html/app.log
  
  # Генерируем HTML с логами
  generate_html > /usr/share/nginx/html/index.html
  
  sleep 5
done &

exec nginx -g 'daemon off;'
