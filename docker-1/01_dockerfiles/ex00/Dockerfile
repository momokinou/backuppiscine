#Basic Dockerfile
FROM alpine:latest

#Set Local dir as Root
WORKDIR /root/

#Install VIM
RUN apk add --no-cache --update vim

#Execute VIM command at start
CMD ["vim"]

#Build : docker build -t install_vim .
#Run : docker run -it install_vim:latest