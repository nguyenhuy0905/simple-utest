FROM fedora:latest

WORKDIR /simple-utest
COPY . /simple-utest
RUN echo "Setting up an environment that's kinda similar to what I use to run this utility"

RUN sudo dnf upgrade -y --refresh

RUN echo "Installing Clang"
RUN sudo dnf install -y clang
# add clang (and everything in bin) to env 
ENV PATH=$PATH:/bin/

RUN ls -a
RUN cd /simple-utest
ENTRYPOINT [ "./docker-run-test.sh" ]
