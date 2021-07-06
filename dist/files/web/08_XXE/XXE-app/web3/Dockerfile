FROM python:3

ADD ./app /opt/app
RUN useradd -s /usr/sbin/nologin ctf &&\
	pip install -r /opt/app/requirements.txt

USER ctf

RUN echo -n "iamsecretfile" > /tmp/secret

CMD ["python", "/opt/app/app.py"]
EXPOSE 5000