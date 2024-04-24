# Rakotoarison-Niaina-Gilbert
    //Installation manuelle d’un paquet à partir du fichier source//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Remarque: pour l’installation des dépendances si on l’a installé à partir d’un fichier source les etapes sont à peu près comme ça sauf pour des cas exceptionnel :
	  1_extraction du fichier source
		  -si c’est un fichier d’extension « .tar.gz » la commande est : « tar xzvf source.tar.gz »
		  -si c’est un fichier d’extension « .tar.bz2 » la commande est : « bunzip source.tar.bz2 ; tar -zvf source.tar» 
	  2_cd source
	  3_make
	  4_sudo make install
    --PHP-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    télécharger le fichier source sur le site officielle de apache : « https://www.php.net/downloads.php » puis téléchargez le fichier
    pour ma part j’ai pris le fichier d’extension « php-8.2.18.tar.gz » mais peu importe l’extension du fichier du moment que c’est le fichier source. 
    Remarque: pour l’ installation, des dépendances sont requises c’est pourquoi j’ai telecharge les de dépendances tels que :
	    *en installant d’un coup : «  sudo apt install -y pkg-config build-essential autoconf bison re2c \
                        libxml2-dev libsqlite3-dev »
	    *ou bien un à un :
		1_pkg-config : « sudo apt install pkg-config » 
		2_sqlite3 : « sudo apt install libsqlite-dev »
		3_libxml2 : « sudo apt install libxml2-dev »
    si tout les dépendances sont là on suit les étapes suivantes et tout devrait se passer sans errreur :
     $ tar xzvf php-8.3.6.tar.gz      		
     $ cd php-8. 3.6				
     $ ./configure
     $ make
     $ sudo make install
    conclusion : ça y est php est installé.

    --Apache--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    télécharger le fichier source sur le site officielle de apache : « https://httpd.apache.org  » puis téléchargez le fichier
    pour ma part j’ai pris le fichier d’extension « httpd-2.4.59.tar.gz » mais peu importe l’extension du fichier du moment que c’est le fichier source. 
    Remarque : pour son installation des dépendances sont requis c’est pourquoi j’ai téléchargé les dépendances tels que :
	
	  *APR et APR-Util:les  décompresser et installé dans « ./srclib » qui se trouve dans « httpd-2.4.59 »
    si tout les dépendances sont là il reste plus qu’a suivre les étapes suivantes :	 	
     $ tar xzvf httpd-2.4.59.tar.gz      		
     $ cd httpd-2.4.59				
     $ cd scrlib
	  1_apr-util-1.6.3 
     		$tar xzvf apr-util-1.6.3
		 $make
		 $sudo make install
	  2_apr-1.7.4
     		$tar xzvf apr-1.7.4
		 $make install
		 $install		
     $ cd httpd-2.4.59	
     $ ./configure --with-include-apr
     $ make
     $ sudo make install
    conclusion : ça y est apache2 est installé.
    --Mysql---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    télécharger le fichier source sur le site officielle de apache : « https://dev.mysql.com»puis téléchargez le fichier
    pour ma part j’ai pris le fichier d’extension «mysql-8.0.36.tar.gz » mais peu importe l’extension du fichier du moment que c’est le fichier source.
    Remarque: pour l’ installation, des dépendances sont requises c’est pourquoi j’ai téléchargé les de dépendances tels que : 
	  -$ sudo apt install build-essential
	  1_pour openssl : $sudo apt install openssl
	  2_des bibliothèques : $sudo apt install libssl-dev
				$sudo apt install libncurses-dev ou bien l’installer manuellement en utilisant un fichier source comme « ncurses.6.4 »
	  3_installer boost-1-77-0 :
		  $>tar xzvf boost-1-77-0.tar.gz
		  -$>cd boost-1-77-0
		  -$>./boostrap.sh
		  -$>./b2
		  -$>sudo ./b2 install
    si tout les dépendances sont là il reste plus qu’a suivre les étapes suivantes :
      $> tar zxvf mysql-8.0.36.tar.gz
      $> cd mysql-8.0.36 »
      $> mkdir build
      $> cd build
      $> cmake ..
      $> make
      $> sudo make install
    conclusion : ça y est mysql est installé.
