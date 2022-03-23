FROM ubuntu:20.04

MAINTAINER CS410.net version: 0.1


ADD converter.cc converter.cc

RUN apt-get update
RUN apt-get install -y g++
RUN g++ -o converter converter.cc

ENTRYPOINT ["./converter"]

