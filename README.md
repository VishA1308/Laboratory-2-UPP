docker build -f Dockerfile.app -t upprpo --progress plain .

docker build -f Dockerfile.web -t upp_web --progress plain .

docker run -p 80:80 -v /var/run/docker.sock:/var/run/docker.sock upp_web

docker-compose up --build
