# practica_pro2


#Crear Repo.
git clone https://github.com/raulva5/practica_pro2.git
git remote add upstream https://github.com/raulva5/practica_pro2.git


#Añadir nuevos ficheros al repositorio.
git add *

#Ver estado repositorio.
git status

#Actualizar git al modificar ficheros.
git commit *


#Subir cambios servidor (Subir).
git push

#Bajar cambios servidor (Estirar).
git pull


TO DO's
	- Fer jocs de prova
	- Començar classe agenda


Propostes Josefina
	- Al fer la consulta entre dates es pot evitar fer-la i enlloc d'aixo fer servir la opció upper and lower BOUNDS 
		(fronteras) del MAP, a la sessio 9 hi ha alguns exemples.
	- El map efectivament s'ordena sol i l'estructura que fa servir és semblant a la d'un arbre
	- La consulta per expressio s'haurà de fer de manera recursiva
	- Els maps retornen coses quan fas certes operacions p.e:
		- Insert retorna bool true o false segons s'ha afegit o no.
		- Erase retorna el número de elements eliminats amb aquella key en un map mai serà més gran a 1 i sera 1 o 0 segons 	en borra o no.
	- El menu serà un vector de iteradors del map<Data, Tasca> i no un vector de <Data> és molt més eficient.
	- Afegir invariants a Data en plan limitant minuts a 59 i hores a 23...
	- Quan no trobes una etiqueta ha de llençar un missatge d'error informant..
	- No vamos a usar el arxivo utils

	//PRES I POST DE MOMENTO SEESSION 8 MAS AVANZADO SESSION 10
	//Grafico doxygen necessita graphviz
	//DOC comentar todos los includes menos los que queremos flexchas