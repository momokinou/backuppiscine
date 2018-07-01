FROM ruby

RUN apt-get update -y && apt-get upgrade -y
RUN gem install rails
RUN apt-get install nodejs -y

ONBUILD COPY . /opt/app

ONBUILD WORKDIR /opt/app

ONBUILD RUN bundle install
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed

# Test 1 : docker build -t docker_rails .
# Test 2 : docker build -t docker_run Dockerfile
# Test 3 :docker run -d -p 3000:3000 ft-rails