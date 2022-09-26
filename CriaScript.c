#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main(void) {
		
	int i,j,n,rp = 10,faixa;
	int l1 = 0,l2 = 0,l3 = 0,l4 = 0,get;
	int i1 = 0,i2 = 0,i3 = 0,i4 = 0,get2;
	int l5 = 0;
	int i5 = 0;
	char dvr,OL = 'S';
    int qdvr,pdvr = 4,contdvr;
    int lik = 0,md;
	char wifi;
	char narquivo[rp];
	
	

	
	
	FILE *pont_arq;
      char c;
      int r;
      		pont_arq = fopen("UsarEste.rsc","w");
    
	    printf("NOME DO CONDOMINIO (max 10 digitos) : ");
		scanf("%s",&narquivo);
		printf("\n");
	    
	    
	    
		
	
		
		
	     	
	    printf("QUANTOS MODELOS DE EQUIPAMENTOS VAO TER: ");
		scanf("%d",&n);
		fflush(stdin);
		printf("\n");
		printf("Digite a faixa de IP: ");
		scanf("%d",&faixa);
		fflush(stdin);
		printf("\n");
		n = n-1;

	
	
	
    struct pessoas {

        char nome[20];
        int idade;
        float altura;
        int porta;
        char serv;
        int pserv;
        

    };

    struct pessoas usuario[10];

    
    for (i=0; i<=n; i++)
    {

        printf("(COLOQUE UMA BARRA NO FINAL DO NOME \"\\\")\n");
        printf("NOME DO EQUIPAMENTO: ");
		fgets(usuario[i].nome, sizeof(usuario[i].nome), stdin);
        printf("\n");
        
        printf("Digite a quantidade de %s ",usuario[i].nome);
        scanf("%f", &usuario[i].altura);
        fflush(stdin);
        printf("\n");
        

        printf("COMPLETE COM O MAIOR IP do %s: ",usuario[i].nome);
        printf("192.168.%d.", faixa);
        scanf("%i", &usuario[i].idade);
        fflush(stdin);
        printf("\n");
        
        printf("Tem porta de servico? (S ou N)");
        scanf("%c",&usuario[i].serv);
        fflush(stdin);
        printf("\n");
        	if(usuario[i].serv=='s' || usuario[i].serv=='S'){
        		printf("Qual a porta de servico? ");
        		scanf("%d",&usuario[i].pserv);
        		fflush(stdin);
        		printf("\n");
			}
			
		
			
        
        
    }
    printf("PARA A ARQUITETURA MIPSBE (1) PARA MMIPS (2)\n");
	    scanf("%c",&wifi);
	    fflush(stdin);
	    printf("\n");
    printf("Vai ter DVR? ");
    printf(" (s para SIM) ");
		scanf("%c",&dvr);
		fflush(stdin);
		printf("\n");
			if(dvr=='s' || dvr=='S'){
        		printf("Quantos DVR? ");
        		scanf("%d",&qdvr);
        		fflush(stdin);
        		printf("\n");
			}
	printf("Ja tem os links? (S=sim N=nao)\n");
	    scanf("%c",&OL);
	    fflush(stdin);
	    printf("\n");
	    	if(OL =='s'||OL =='S'){
	    		printf("Quantos links irao ter? ");
				scanf("%d",&lik);
				fflush(stdin);
				printf("\n");
				
					if(lik==1){
						printf("Digite o ip do MODEM 1 (Use espaco entre as centenas)\n");
						scanf("%d" "%d" "%d" "%d" , &l1,&l2,&l3,&l4);
						fflush(stdin);
						printf("\n");
						if(l3==1){
							i1=192;
							i2 = 168;
							i3 = 0;
							i4 = 1;
						}
						else if(l3==0){
							i1=192;
							i2 = 168;
							i3 = 1;
							i4 = 1;
						}
						
					}
					else{
						printf("Digite o ip do MODEM 1 (Use espaco entre as centenas)\n");
						scanf("%d" "%d" "%d" "%d" , &l1,&l2,&l3,&l4);
						fflush(stdin);
						printf("\n");
						printf("Digite o ip do MODEM 2 (Use espaco entre as centenas)\n");
						scanf("%d" "%d" "%d" "%d" , &i1,&i2,&i3,&i4);
						fflush(stdin);
						printf("\n");
			}
			}
	    	else{
	    					i1=192;
							i2 = 168;
							i3 = 1;
							i4 = 1;
							l1 = 192;
							l2 = 168;
							l3 = 0;
							l4 = 1;
			}
			
    l5 = l4 +1;
	i5 = i4 +1;
	
	fprintf(pont_arq,"/interface ethernet\n");
	fprintf(pont_arq,"set [ find default-name=ether1 ] comment=\"WAN 1\"\nset [ find default-name=ether2 ] comment=\"WAN 2\"\nset [ find default-name=ether3 ] comment=\"WAN 3\"\nset [ find default-name=ether4 ] comment=\"WAN 4\"\nset [ find default-name=ether5 ] comment=LAN\n");
	fprintf(pont_arq,"/ip address\n");
	fprintf(pont_arq,"add address=192.168.%d.1/24 interface=ether5 network=192.168.%d.0\n",faixa, faixa);
	fprintf(pont_arq,"add address=%d.%d.%d.%d/24 interface=ether2 network=%d.%d.%d.0\n",i1,i2,i3,i5,i1,i2,i3);
	fprintf(pont_arq,"add address=%d.%d.%d.%d/24 interface=ether1 network=%d.%d.%d.0\n",l1,l2,l3,l5,l1,l2,l3 );
	

		
	fprintf(pont_arq,"/ip dns\nset servers=8.8.8.8,8.8.4.4\n");
	fprintf(pont_arq,"/ip firewall address-list\nadd address=132.255.93.208 list=ips_wan\nadd address=%d.%d.%d.%d list=ips_wan\n",l1,l2,l3,l5);
	fprintf(pont_arq,"add address=%d.%d.%d.%d list=ips_wan\n",i1,i2,i3,i5);
	fprintf(pont_arq,"add address=8.8.8.8 list=ips_dyndns\nadd address=162.88.193.70 list=ips_dyndns\nadd address=131.186.113.70 list=ips_dyndns\nadd address=216.146.43.71 list=ips_dyndns\n");
	fprintf(pont_arq,"add address=216.146.43.70 list=ips_dyndns\nadd address=131.186.161.70 list=ips_dyndns\nadd address=91.198.22.70 list=ips_dyndns\nadd address=216.146.38.70 list=ips_dyndns\nadd address=162.88.96.194 list=ips_dyndns\nadd address=131.186.113.135 list=ips_dyndns\nadd address=131.186.113.136 list=ips_dyndns\n");
	fprintf(pont_arq,"add address=162.88.100.200 list=ips_dyndns\nadd address=132.226.8.169 list=ips_dyndns\nadd address=132.226.247.73 list=ips_dyndns\nadd address=193.122.130.0 list=ips_dyndns\nadd address=158.101.44.242 list=ips_dyndns\n");
	fprintf(pont_arq,"/ip firewall filter\nadd action=drop chain=input comment=\"Block mikrotik access by wan\" disabled=\\\nno dst-port=22,80 in-interface=ether1 protocol=tcp\nadd action=drop chain=input disabled=no dst-port=22,80 in-interface=ether2 \\\nprotocol=tcp\nadd action=drop chain=input disabled=no dst-port=22,80 in-interface=ether3 \\\nprotocol=tcp\nadd action=drop chain=input disabled=no dst-port=22,80 in-interface=ether4 \\\n");
	fprintf(pont_arq,"protocol=tcp\nadd action=drop chain=forward comment=\"Bloqueia Consulta DNS publica\" \\\ndisabled=no dst-address-list=ips_wan dst-port=53 protocol=udp\nadd action=drop chain=input disabled=no dst-address-list=ips_wan dst-port=53 \\\nprotocol=udp\n");
	
	fprintf(pont_arq,"/ip firewall mangle\n");
	fprintf(pont_arq,"add action=mark-routing chain=output comment=\"Marca\\E7\\E3o dado para envio de link\" dst-port=443 new-routing-mark=sendip passthrough=yes protocol=tcp src-address=!192.168.%d.0/24\n",faixa);
	fprintf(pont_arq,"add action=mark-routing chain=output comment=DynDNS dst-address-list=ips_dyndns new-routing-mark=http passthrough=yes protocol=tcp\n");
	fprintf(pont_arq,"add action=mark-routing chain=prerouting comment=\"Marca\\E7\\E3o dado para envio de link\" disabled=yes dst-port=8060,8061 new-routing-mark=route-wan2 passthrough=yes protocol=udp\n");
	fprintf(pont_arq,"add action=accept chain=prerouting comment=\"Permite Acesso as redes\" dst-address=192.168.10.0/24 src-address=192.168.10.0/24\n");
	fprintf(pont_arq,"add action=accept chain=prerouting dst-address=192.168.0.0/24 src-address=192.168.10.0/24\n");
	fprintf(pont_arq,"add action=accept chain=prerouting dst-address=192.168.100.0/24 src-address=192.168.10.0/24\n");
	fprintf(pont_arq,"add action=accept chain=prerouting dst-address=192.168.2.0/24 src-address=192.168.10.0/24\n");
	fprintf(pont_arq,"add action=accept chain=prerouting dst-address=192.168.3.0/24 src-address=192.168.10.0/24\n");
	fprintf(pont_arq,"add action=mark-connection chain=input comment=\"WAN 1\" in-interface=ether1 new-connection-mark=conn-wan1 passthrough=yes\n");
	fprintf(pont_arq,"add action=mark-connection chain=prerouting in-interface=ether1 new-connection-mark=conn-wan1 passthrough=yes\n");
	fprintf(pont_arq,"add action=mark-routing chain=prerouting connection-mark=conn-wan1 in-interface=ether5 new-routing-mark=route-wan1 passthrough=yes\n");
	fprintf(pont_arq,"add action=mark-routing chain=output connection-mark=conn-wan1 new-routing-mark=route-wan1 passthrough=yes\n");
	fprintf(pont_arq,"add action=mark-connection chain=input comment=\"WAN 2\" in-interface=ether2 new-connection-mark=conn-wan2 passthrough=yes\n");
	fprintf(pont_arq,"add action=mark-connection chain=prerouting in-interface=ether2 new-connection-mark=conn-wan2 passthrough=yes\n");
	fprintf(pont_arq,"add action=mark-routing chain=prerouting connection-mark=conn-wan3 in-interface=ether5 new-routing-mark=route-wan2 passthrough=yes\n");
	fprintf(pont_arq,"add action=mark-routing chain=output connection-mark=conn-wan2 new-routing-mark=route-wan2 passthrough=yes\n");
	
	fprintf(pont_arq,"/ip firewall nat\n");
	fprintf(pont_arq,"add action=accept chain=dstnat comment=\"Winbox Access\" dst-port=8250 protocol=tcp\n");
	fprintf(pont_arq,"add action=accept chain=dstnat comment=\"Winbox Access\" dst-port=8250 protocol=tcp\n");
	fprintf(pont_arq,"add action=accept chain=srcnat comment=\"NAT WAN 1\" out-interface=ether1\n");
	fprintf(pont_arq,"add action=masquerade chain=srcnat out-interface=ether1\n");
	fprintf(pont_arq,"add action=masquerade chain=srcnat out-interface=ether2\n");
	fprintf(pont_arq,"add action=masquerade chain=srcnat out-interface=ether3\n");
	fprintf(pont_arq,"add action=masquerade chain=srcnat out-interface=ether4\n");
	fprintf(pont_arq,"add action=dst-nat chain=dstnat comment=Wi-Fi dst-address-list=ips_wan dst-port=8254 protocol=tcp to-addresses=192.168.10.254 to-ports=80\n");
	fprintf(pont_arq,"add action=dst-nat chain=dstnat comment=MODEM dst-address-list=ips_wan dst-port=8181 protocol=tcp to-addresses=%d.%d.%d.%d to-ports=80\n",l1,l2,l3,l4);
	fprintf(pont_arq,"add action=dst-nat chain=dstnat dst-port=8282 protocol=tcp to-addresses=192.168.15.1 to-ports=80 \n");
	fprintf(pont_arq,"add action=dst-nat chain=dstnat dst-port=8383 protocol=tcp to-addresses=%d.%d.%d.%d to-ports=80\n",i1,i2,i3,i4);
	fprintf(pont_arq,"add action=dst-nat chain=dstnat dst-port=8484 protocol=tcp to-addresses=192.168.3.1 to-ports=80\n");
	fprintf(pont_arq,"add action=dst-nat chain=dstnat dst-port=8585 protocol=tcp to-addresses=192.168.4.1 to-ports=80\n");
	
		if(dvr=='s'||dvr=='S'){
			int rtsp = 7;
			int ndvr = 1;
			for(contdvr=qdvr;contdvr>0;contdvr--){
			fprintf(pont_arq,"add action=dst-nat chain=dstnat comment=\"DVR%d\" dst-port=3777%d protocol=tcp to-addresses=\\\n",ndvr,rtsp);
    		fprintf(pont_arq,"192.168.%d.20%d to-ports=3777%d\n",faixa,pdvr,rtsp);
    		fprintf(pont_arq,"add action=dst-nat chain=dstnat dst-port=820%d protocol=tcp to-addresses=\\\n",pdvr);
    		fprintf(pont_arq,"192.168.%d.20%d to-ports=80\n",faixa,pdvr);
    		fprintf(pont_arq,"add action=dst-nat chain=dstnat dst-port=855%d protocol=tcp to-addresses=\\\n",pdvr);
    		fprintf(pont_arq,"192.168.%d.20%d to-ports=554\n",faixa,pdvr);
    		pdvr--;
    		rtsp--;
    		ndvr++;
			}
			
			
    		
		}


	
	
	
    for (i=0; i<=n; i++){  
    
		if(usuario[i].serv=='s' || usuario[i].serv=='S'){
	    	fprintf(pont_arq,"add action=dst-nat chain=dstnat comment=\"%s\" dst-port=8%d protocol=\\\n",usuario[i].nome,usuario[i].idade);
			fprintf(pont_arq,"tcp to-addresses=192.168.%d.%d to-port=80\n",faixa ,usuario[i].idade);
			fprintf(pont_arq,"add action=dst-nat chain=dstnat dst-port=3%d protocol=tcp to-addresses=\\\n",usuario[i].idade);
			fprintf(pont_arq,"192.168.%d.%d to-port=%d\n",faixa,usuario[i].idade,usuario[i].pserv);
			usuario[i].idade--;
			usuario[i].altura--;
			for(j=usuario[i].altura;j>0;j--){
	    		
	    		
	    		if (usuario[i].altura>1){
	    		 	fprintf(pont_arq,"add action=dst-nat chain=dstnat dst-port=8%d protocol=tcp to-addresses=\\\n",usuario[i].idade);
					fprintf(pont_arq,"192.168.%d.%d to-port=80\n",faixa,usuario[i].idade);
					fprintf(pont_arq,"add action=dst-nat chain=dstnat dst-port=3%d protocol=tcp to-addresses=\\\n",usuario[i].idade);
					fprintf(pont_arq,"192.168.%d.%d to-port=%d\n",faixa,usuario[i].idade,usuario[i].pserv);
				 }
	    		usuario[i].idade--;
			}
	
		
		}
			else{
				fprintf(pont_arq,"add action=dst-nat chain=dstnat comment=\"%s",usuario[i].nome);
				fprintf(pont_arq,"\" dst-port=8%d protocol=\\\n",usuario[i].idade);
				fprintf(pont_arq,"tcp to-addresses=192.168.%d.%d to-port=80\n",faixa ,usuario[i].idade);
				usuario[i].idade--;
				usuario[i].altura--;
		
    		for(j=usuario[i].altura;j>0;j--){
    		
    		
	    		if (usuario[i].altura>1){
	    		 	fprintf(pont_arq,"add action=dst-nat chain=dstnat dst-port=8%d protocol=tcp to-addresses=\\\n",usuario[i].idade);
					fprintf(pont_arq,"192.168.%d.%d to-port=80\n",faixa,usuario[i].idade);
				 }
				 
    			usuario[i].idade--;
			}
			
		}

    }
    
    fprintf(pont_arq,"/ip firewall service-port\nset ftp disabled=yes\nset tftp disabled=yes\nset irc disabled=yes\nset h323 disabled=yes\nset sip ports=55066,55067,5060,5061 sip-timeout=2m\nset pptp disabled=yes\nset udplite disabled=yes\nset dccp disabled=yes\nset sctp disabled=yes\n");

	fprintf(pont_arq,"/ip route\n");
	fprintf(pont_arq,"add comment=\"SEND IP SERVER\" distance=1 gateway=%d.%d.%d.%d routing-mark=\\\nsendip\n" ,l1,l2,l3,l4);
	fprintf(pont_arq,"add distance=1 gateway=%d.%d.%d.%d routing-mark=route-wan2\n" ,i1,i2,i3,i4);
	fprintf(pont_arq,"add distance=1 gateway=%d.%d.%d.%d routing-mark=route-wan1\n",l1,l2,l3,l4);
	fprintf(pont_arq,"add distance=1 gateway=192.168.3.1 routing-mark=route-wan3\n");
	fprintf(pont_arq,"add distance=1 gateway=192.168.4.1 routing-mark=route-wan4\n");
	fprintf(pont_arq,"add comment=\"WAN 2\" distance=2 gateway=%d.%d.%d.%d\n" ,i1,i2,i3,i4);
	fprintf(pont_arq,"add comment=\"WAN 1\" distance=3 gateway=%d.%d.%d.%d\n" ,l1,l2,l3,l4);
	fprintf(pont_arq,"add comment=\"WAN 3\" disabled=yes distance=4 gateway=192.168.3.1\n");
	fprintf(pont_arq,"add comment=\"WAN 4\" disabled=yes distance=5 gateway=192.168.4.1\n");
	fprintf(pont_arq,"add comment=\"WAN Test 1\" disabled=yes distance=1 dst-address=8.8.8.8/32 \\\ngateway=%d.%d.%d.%d\n" , l1,l2,l3,l4);
	fprintf(pont_arq,"add comment=\"WAN Test 2\" disabled=yes distance=1 dst-address=200.160.2.3/32 \\\ngateway=%d.%d.%d.%d\n" , i1,i2,i3,i4);

	fprintf(pont_arq,"/ip service\nset telnet disabled=yes\nset ftp disabled=yes\nset www disabled=yes port=8888\nset ssh disabled=yes\nset api port=8251\nset winbox port=8250\nset api-ssl disabled=yes\n");

	fprintf(pont_arq,"/ip ssh\nset allow-none-crypto=yes forwarding-enabled=remote\n/snmp\nset enabled=yes\n/system clock\nset time-zone-autodetect=no time-zone-name=America/Sao_Paulo\n/system identity\nset name=%s\n",narquivo);
	
		if(wifi=='1'){
			fprintf(pont_arq,"/system leds\nset 3 interface=ether4 type=interface-status\nset 4 interface=ether5 type=interface-status\n/system logging\n");
			fprintf(pont_arq,"set 0 action=echo\n/system ntp client\nset enabled=yes\n");
			
			fprintf(pont_arq,"/system routerboard settings\n");
			fprintf(pont_arq,"set silent-boot=no\n");
			fprintf(pont_arq,"/system scheduler\n");
			fprintf(pont_arq,"add interval=30s name=test-wans on-event=test-wans policy=\\\n");
		    fprintf(pont_arq,"ftp,reboot,read,write,policy,test,password,sniff,sensitive start-date=\\\n");
		    fprintf(pont_arq,"jan/01/1970 start-time=00:00:30\n");
			fprintf(pont_arq,"add interval=1m name=verify-ip on-event=verify-ip policy=\\\n");
		    fprintf(pont_arq,"ftp,reboot,read,write,policy,test,password,sniff,sensitive start-date=\\\n");
		    fprintf(pont_arq,"jan/01/1970 start-time=00:01:00\n");
			fprintf(pont_arq,"add interval=5d name=backup on-event=backup policy=\\\n");
		    fprintf(pont_arq,"ftp,reboot,read,write,policy,test,password,sniff,sensitive start-date=\\\n");
		    fprintf(pont_arq,"jan/01/1970 start-time=23:15:00\n");
			fprintf(pont_arq,"add interval=8h name=clear-log on-event=\"");
			fprintf(pont_arq,"/system logging action\\r\\\n");
		    fprintf(pont_arq,"\\nset 0 memory-lines=1\\r\\\n");
		    fprintf(pont_arq,"\\nset 0 memory-lines=100\\r\\\n");
		    fprintf(pont_arq,"\\n:log info (\\\"Limpeza de memoria executada!\\\")\" policy=\\\n");
		    fprintf(pont_arq,"ftp,reboot,read,write,policy,test,password,sniff,sensitive start-date=\\\n");
		    fprintf(pont_arq,"jan/01/1970 start-time=08:00:00\n");
		}
		else if (wifi =='2'){
			fprintf(pont_arq,"/system scheduler\n");
			fprintf(pont_arq,"add interval=1m name=verify-ip on-event=verify-ip policy=\\\n");
			fprintf(pont_arq,"    ftp,reboot,read,write,policy,test,password,sniff,sensitive,romon \\\n");
			fprintf(pont_arq,"    start-date=jan/01/1970 start-time=00:01:00\n");
			fprintf(pont_arq,"add interval=30s name=test-wans on-event=test-wans policy=\\\n");
			fprintf(pont_arq,"    ftp,reboot,read,write,policy,test,password,sniff,sensitive,romon \\\n");
			fprintf(pont_arq,"    start-date=jan/01/1970 start-time=00:00:30\n");
			fprintf(pont_arq,"add interval=8h name=clear-log on-event=\"/system logging action\\r\\\n");
			fprintf(pont_arq,"    \\nset 0 memory-lines=1\\r\\\n");
			fprintf(pont_arq,"    \\nset 0 memory-lines=100\\r\\\n");
			fprintf(pont_arq,"    \\n:log info (\\\"Limpeza de memoria executada!\\\")\" policy=\\\n");
			fprintf(pont_arq,"    ftp,reboot,read,write,policy,test,password,sniff,sensitive,romon \\\n");
			fprintf(pont_arq,"    start-date=jan/01/1970 start-time=08:00:00\n");
			fprintf(pont_arq,"add interval=5d name=backup on-event=backup policy=\\\n");
			fprintf(pont_arq,"    ftp,reboot,read,write,policy,test,password,sniff,sensitive,romon \\\n");
			fprintf(pont_arq,"    start-date=jan/01/1970 start-time=23:15:00\n");
		}
	
	
	
	
	FILE *arq;
    /*Quantidade de linhas (pode servir pra algum calculo estatistico)*/
    int quant=0 , t;
   /*Tamanho de caracteres encontrados em uma linha (chute)*/
    char linha[10];
	if(wifi=='1'){
		/*//NÃ£o foi feito aqui aquele teste pra saber se o arquivo foi lido corretamente (nÃ£o precisei)*/
    arq = fopen("script.txt", "r");
    for (t=0; t<1988; t++){
   fgets(linha, sizeof(linha), arq);
   fprintf(pont_arq,"%s",linha);
	}
	}
    
    else if (wifi=='2'){
    	/*//NÃ£o foi feito aqui aquele teste pra saber se o arquivo foi lido corretamente (nÃ£o precisei)*/
    arq = fopen("scriptmmips.txt", "r");
	for (t=0; t<1991; t++){
   fgets(linha, sizeof(linha), arq);
   fprintf(pont_arq,"%s",linha);
	}
	}
    
    /*//Enquanto nÃ£o alcanÃ§ar o fim do arquivo, faÃ§a o seguinte linha por linha:*/
    
    fclose(arq);


    system("cls");
    
	printf("AGORA TEM UM ARQUIVO NA MESMA PASTA COM O NOME DE UsarEste QUE DEVE SER RENOMEADO\n");
    printf("Valeu!!!!!") ;
	
	fclose(pont_arq);


    printf("\n\n");
    return(0);
}