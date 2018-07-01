#Basic Dockerfile
#Debian is OS (Taking latest Version)
FROM debian

#Set the workdir to the /home
WORKDIR /opt

EXPOSE  9987:9987
EXPOSE  10011:10011
EXPOSE  30033:30033

#INstalling and Updating Packages
RUN apt-get update -y && apt-get upgrade -y && apt-get install -y wget tar bzip2 xz-utils

#creating User without password
RUN adduser --disabled-password --gecos "" teamspeak \
    && mkdir /opt/teamspeak \
    && chown teamspeak:teamspeak /opt/teamspeak/ \
    && chmod 0770 /opt/teamspeak/

#Downloading Teamspeak 3 Server archive
RUN wget "http://dl.4players.de/ts/releases/3.1.1/teamspeak3-server_linux_amd64-3.1.1.tar.bz2" \
    && tar -xf /opt/teamspeak3-server_linux_amd64-3.1.1.tar.bz2 && rm /opt/teamspeak3-server_linux_amd64-3.1.1.tar.bz2 \
    && mv -f teamspeak3-server_linux_amd64/* teamspeak

# Running Mininal Start script
ENTRYPOINT ["/bin/sh", "./teamspeak/ts3server_minimal_runscript.sh"]

# To Test 
# Build : docker build -t ftts .
# Run : docker run -d -e TS3SERVER_LICENSE=accept --publish=9987:9987/udp --publish=30033:30033/tcp --publish=10011:10011/tcp ftts
