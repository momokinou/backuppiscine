#From Ruby Image
FROM ruby

#Preparation image + installation dependencies needed
RUN apt-get update -y && apt-get upgrade -y
RUN gem install rails
RUN apt-get install nodejs -y

#Copy fichier travail a la loc voulu
ONBUILD COPY . /opt/app

#Set workdir au build
ONBUILD WORKDIR /opt/app

#on build Run des diff commandes pour set database + Run  Ruby on rails app
ONBUILD RUN bundle install | tee ./logs.log
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed

# Test 1 : docker build -t docker_rails .
# Test 2 : docker build -t docker_run Dockerfile
# Test 3 :docker run -d -p 3000:3000 ft-rails
