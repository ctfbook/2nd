FROM python:3

ADD ./app /opt/app
RUN apt-get update -y&&\
    apt-get install -y default-mysql-client &&\
	useradd -s /usr/sbin/nologin ctf &&\
	pip3 install -r /opt/app/requirements.txt

USER ctf

CMD ["python", "/opt/app/app.py"]
EXPOSE 5000