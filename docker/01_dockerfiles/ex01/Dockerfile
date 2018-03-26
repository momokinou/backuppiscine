FROM debian

#Installation du necessaire
RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install curl -y
RUN apt-get install bzip2 -y

#Configuration du TS3

# Ouverture des Ports
EXPOSE 9987/udp
EXPOSE 30033
EXPOSE 10011
EXPOSE 41144

#Preparation
RUN user ts3
WORKDIR /home/ts3

#Installation
RUN curl http://dl.4players.de/ts/releases/3.1.1/teamspeak3-server_linux_amd64-3.1.1.tar.bz2
RUN tar -xvf teamspeak3-server_linux_amd64-3.1.1.tar.bz2
WORKDIR teamspeak3-server_linux_amd64
COPY ts3server.ini /home/t3/teamspeak3-server_linux_amd64/ts3server.ini
USER ts3
ENTRYPOINT ["sh", "ts3server_minimal_runscript.sh", "inifile=ts3server.ini"]
