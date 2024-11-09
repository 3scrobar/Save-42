#!/usr/bin/bash

while true; do
	git add .  # Ajoute tous les fichiers modifiés au staging area
	sleep 1  # Attendre 1 seconde (facultatif)

	# Utilisation de 'date' pour formater l'heure et la date
	# $(date "+%Y-%m-%d %H:%M:%S") : format personnalisé pour inclure année, mois, jour, heure, minute et seconde
	git commit -m "autosave $(date "+%Y-%m-%d %H:%M:%S")"  # Commit avec la date et l'heure dans le message
	sleep 1  # Attendre 1 seconde avant de pousser (facultatif)

	git push  # Pousser les changements vers le dépôt distant
	sleep 300  # Attendre 5 minutes avant de recommencer (300 secondes)
done
