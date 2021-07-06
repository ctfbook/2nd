FROM selenium/standalone-chrome

USER root
ADD ./app /opt/app

RUN apt-get update &&\
	apt-get install -y python3-pip libcurl4 libcurl4-gnutls-dev librtmp-dev

RUN	useradd -s /usr/sbin/nologin ctf &&\
	pip3 install -r /opt/app/requirements.txt

USER ctf

CMD ["python3", "/opt/app/app.py"]
EXPOSE 5000