all: main_client main_server

main_client: main_client.o print.o validate.o main_clnt.o main_xdr.o
	gcc -g -o main_client print.o validate.o main_clnt.o main_client.o main_xdr.o `pkg-config --cflags --libs gtk+-2.0` -lnsl
print.o: print.c
	gcc -g   -c -o print.o print.c
validate.o: validate.c
	gcc -g   -c -o validate.o validate.c
main_clnt.o: main_clnt.c
	gcc -g   -c -o main_clnt.o main_clnt.c
main_client.o: main_client.c
	gcc -c main_client.c `pkg-config --cflags --libs gtk+-2.0`
main_xdr.o: main_xdr.c
	gcc -g   -c -o main_xdr.o main_xdr.c

main_server: validate.o main_svc.o main_server.o main_xdr.o -lnsl
	gcc -g -o main_server validate.o main_svc.o main_server.o main_xdr.o -lnsl
main_svc.o: main_svc.c
	gcc -g   -c -o main_svc.o main_svc.c

clean:
	rm -f *.o *~ main_client main_server
