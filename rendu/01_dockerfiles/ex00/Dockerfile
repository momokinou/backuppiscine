#Basic Dockerfile
FROM alpine:3.5

#Set Local dir as Root
WORKDIR /root/

#Install VIM
RUN apk add --no-cache --update vim

#Execute VIM command at start
ENTRYPOINT vim

#Build : docker build -t ftvim .
#Run : docker run -it ftvim:latest