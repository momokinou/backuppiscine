FROM Ruby

#Installation du necessaire
RUN apt-get upgrade -y && apt-get update -y
RUN apt-get install nodejs -y
RUN gem install rails

#OnBuild Copy
ONBUILD COPY app/ opt/app
ONBUILD WORKDIR opt/app

#OnBuild Init
ONBUILD RUN install bundle
ONBUILD RUN rails db:
ONBUILD RUN rails db:seed
