FROM ubuntu:20.04
LABEL Description="EP_Build_Environment"

## Base install
RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    gdb \
    wget \
    git \
    libssl-dev \
    openssl \
    libtool \
    autoconf \
    automake \
    build-essential \
    uuid-dev \
    libxi-dev \
    libopenal-dev \
    libgl1-mesa-dev \
    libglw1-mesa-dev \
    libxrandr-dev \
    libxinerama-dev\
    libxcursor-dev \
    freeglut3-dev \
    curl \
    unzip
## Python
RUN apt-get update && apt-get -y --no-install-recommends install python3.8
RUN ln -s /usr/bin/pip3 /usr/bin/pip
RUN ln -s /usr/bin/python3.8 /usr/bin/python
## setup config
RUN ln -fs /usr/share/zoneinfo/UTC /etc/localtime
RUN DEBIAN_FRONTEND=noninteractive  apt-get update &&  apt-get install -y --no-install-recommends \
    apt-transport-https ca-certificates gnupg \
    software-properties-common
## cmake
ARG CMAKE_VERSION=3.21.0
RUN wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-Linux-x86_64.sh \
      -q -O /tmp/cmake-install.sh \
      && chmod u+x /tmp/cmake-install.sh \
      && mkdir /usr/bin/cmake \
      && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
      && rm /tmp/cmake-install.sh
## install ccache
RUN apt-get update &&  apt-get install -y --no-install-recommends ccache
ENV PATH="/usr/lib/ccache:/usr/bin/cmake/bin:${PATH}"
## add non root user

ARG USERNAME=ngkhanh
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    #
    # [Optional] Add sudo support. Omit if you don't need to install software after connecting.
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# ********************************************************
# * Anything else you want to do like clean up goes here *
# ********************************************************
### add VSCode extension_install to avoid reinstall
RUN mkdir -p /home/$USERNAME/.vscode-server/extensions \
        # /home/$USERNAME/.vscode-server-insiders/extensions \
    && chown -R $USERNAME \
        /home/$USERNAME/.vscode-server
        # /home/$USERNAME/.vscode-server-insiders


# [Optional] Set the default user. Omit if you want to keep the default as root.
USER $USERNAME

WORKDIR /home/$USERNAME

## set run
# CMD ["/bin/bash","-c"]
