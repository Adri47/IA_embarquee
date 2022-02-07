IA Embarquee

Compilation et execution
	1) Créer un dossier build
	2) Entrer les commandes suivantes :
		$cd build/
		$cmake
	3) Compiler le projet :
	   $make all
	4) Executer le projet :
	   $./ProjetIA
	   
Connexion et copie de fichiers vers raspberry :

	$ssh login@ssh.enseirb.fr #connexion ssh enseirb
	$ssh -p 223 pi_12@147.210.204.173 #connexion a la raspberry groupe n°12 (mdp : hackermen)

	Copie dossier local vers SSH ENSIERB (Sur PC local) :
	$scp -r /home/adrien/Documents/GitHub/IA_embarquee/Projet/codeC/Inference aclain002@ssh.enseirb.fr:~/IA	#copie d'un dossier local vers disque ENSEIRB
	
	Copier dossier ENSEIRB vers Rasp:
	#scp -r -P 2223 ~/IA pi_12@147.210.204.173:~/Inference
	
	Recuperer photo prise vers SSH ENSEIRB
	$scp -r ~IA/toto.bmp pi_12@147.210.204.173:~/	#copie d'un fichier de ENSEIRB  vers rasp 
	
	$raspistill -e bmp -w 64 -h 64 -o name.bmp  #prendre une photo 64x64 
