#From Ruby Image
FROM ruby

#We prepare our image and install every dependencies we need.
RUN apt-get update -y && apt-get upgrade -y
RUN gem install rails
RUN apt-get install nodejs -y

#We copy current working folder into required location
ONBUILD COPY . /opt/app

#We set the Workdir on the build
ONBUILD WORKDIR /opt/app

#on build we run the different commands that set Databse, and Ruby on rails app
ONBUILD RUN bundle install | tee ./logs.log
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed

# Test 1 : docker build -t docker_rails .
# Test 2 : docker build -t docker_run Dockerfile
# Test 3 :docker run -d -p 3000:3000 ft-rails