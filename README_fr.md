# QmlWidgetTranslator

Qml Widget Translator est un projet de modèle pour QML et QtWidgets.

Le concept est simple, je voulais un Qt Temple qui puisse être utilisé pour de nombreux OS,
ainsi que des contraintes, j'en avais besoin pour fonctionner avec SQL et sans lui,
avec stockage local et sans,
mais je ne voulais pas écrire une application QML ou Qt Widget en C++,
et toutes les variantes auxquelles je dois faire face,
ce modèle est donc conçu pour contourner tous ces problèmes.

J'utilise cmake mais le fichier qmake est obligatoire si vous voulez l'utiliser pour les fichiers de traduction,
à part ça, je n'utilise que le fichier cmake, et vous trouverez des définitions de précomipler pour beaucoup de choses comme :

* MY_QML : lorsque vous travaillez dans QML, réglez-le sur ON, si le mode QWidget réglez-le sur OFF
* USE_SQL_FLAG : si vous souhaitez utiliser SQL activé, si vous souhaitez créer WebAssembly et devez désactiver SQL et le stockage local, définissez-le sur OFF.
* MY_INTERNET_CHECK_PING : utilisé si votre application a besoin de vérifications d'accès à Internet
* DO_LUPDATE : mise à jour de la traduction
* DO_LRELEASE : Traduction lrelease
* MY_TS_FILES : fichiers TS de traduction
* MY_QM_FILES : fichiers QM de traduction
* EN-TÊTES : fichiers d'en-tête
* PROJECT_APP_HEADER : fichiers d'en-tête QWidget
* PROJECT_SOURCES : fichiers sources
* PROJECT_UI : fichiers d'interface utilisateur QWidget
* PROJECT_APP_SOURCE : fichiers source QWidget
* ANDROID : Mode Android
* MY_URL : pour Mac

Je travaille actuellement sur toutes les fonctionnalités des widgets Qt en C++, j'ai donc désactivé MY_QML,
actuellement QML n'a pas les fonctionnalités du QWidget,
mais je prévois de changer de vitesse et d'activer MY_QML et de créer le même ensemble de fonctionnalités.

# Doxygène

J'utilise Doxygen, vous pouvez l'exécuter à partir des commandes ci-dessous.

```bash
doxygen Doxyfile

ou

magicien doxy
```

J'ai des documents Doxygen sous docs.



## Statut

[![Appveyor Build Status](https://ci.appveyor.com/api/projects/status/j7htumuwfx31elf6?svg=true)](https://ci.appveyor.com/project/Light-Wizzard/QmlWidgetTranslator)

## :package : **Téléchargements :**

- :pingouin: [Linux](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator-x86_64.AppImage)
- :office : [Windows zip exe](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator_release.zip)
- :apple : [Apple](https://github.com/Light-Wizzard/QmlWidgetTranslator/releases/download/continuous/QmlWidgetTranslator.dmg)

Windows (Testé sur 7 et 10, dites-moi si 8 fonctionne) : Téléchargez zip et extrayez-le, puis exécutez le fichier QmlWidgetTranslator.exe à l'intérieur du dossier de déploiement.

# A propos de l'auteur

Tous mes livres sont gratuits en ligne sur http://LightWizzard.com, mais les imprimer ou envoyer des ePubs sur votre appareil coûte de l'argent.

Je ne publie pas mes livres ici, vous pouvez les lire gratuitement sur mon
[Compte Github Light-Wizzard/The-Principles-Of-The-Trinary-Universe](https://github.com/Light-Wizzard/The-Principles-Of-The-Trinary-Universe),
mais vous devez payer pour des livres imprimés, ou la facilité d'avoir un ePub livré via vos appareils ePub Reader, sans avoir à le télécharger.

Livre imprimé et ePub disponible sur :

Loulou
* :livre: :ordinateur: http://www.lulu.com/spotlight/LightWizzard

Amazone
* :book: Book https://www.amazon.com/Principles-Trinary-Universe-according-Johannes/dp/1795429186/
* :ordinateur : ePub https://www.amazon.com/Principles-Trinary-Universe-according-Johannes-ebook/dp/B086D24HX9

## Progrès du développement

Si vous ne voyez pas votre système d'exploitation, téléchargez-le, extrayez-le dans un dossier et ouvrez-le avec Qt Creator,
qui doit être installé, et le compiler ou l'exécuter.


Fin du fichier README.md