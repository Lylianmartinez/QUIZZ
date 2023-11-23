#include <stdio.h>
#include <stdbool.h>

// Structure pour une question du quiz sur le football
struct Question {
    char question[150];
    char reponses[4][50]; // Options pour les questions à choix unique
    int vraiFaux; // Pour les questions vrai/faux (1 pour vrai, 0 pour faux)
    int type; // Type de question (1 pour choix unique, 2 pour vrai/faux)
    int reponseUtilisateur; // Stocke la réponse de l'utilisateur
};

// Fonction pour afficher une question
void afficherQuestion(struct Question q) {
    printf("Question: %s\n", q.question);
    if (q.type == 1) {
        printf("Options:\n");
        for (int i = 0; i < 4; ++i) {
            printf("%d. %s\n", i + 1, q.reponses[i]);
        }
    }
    else if (q.type == 2) {
        printf("Vrai/Faux: %s\n", q.vraiFaux ? "Vrai" : "Faux");
    }
}

int saisirReponse(void) {
    int choix;
    printf("Entrez votre réponse: ");
    scanf("%d", &choix);

    // Consommer le caractère de nouvelle ligne restant dans le flux d'entrée
    while (getchar() != '\n');

    return choix;
}

// Fonction pour évaluer les réponses de l'utilisateur
void evaluerReponses(struct Question questions[], int taille) {
    int score = 0;
    for (int i = 0; i < taille; ++i) {
        afficherQuestion(questions[i]);
        questions[i].reponseUtilisateur = saisirReponse();

        // Vérifier si la réponse de l'utilisateur est correcte
        if (questions[i].reponseUtilisateur == questions[i].vraiFaux + 1 ||
            (questions[i].type == 1 && strcmp(questions[i].reponses[questions[i].reponseUtilisateur - 1], "Vrai") == 0)) {
            printf("Bonne réponse!\n");
            score++;
        }
        else {
            printf("Mauvaise réponse!\n");
        }
    }
    printf("Votre score final est : %d/%d\n", score, taille);
}

int main() {
    // Exemple de questions pour le quiz sur le football
    struct Question questions[3] = {
        {"Quelle équipe a remporté la Coupe du Monde 2018?", {"France", "Croatie", "Belgique", "Angleterre"}, 1, 1},
        {"Lionel Messi a remporté plus de Ballons d'Or que Cristiano Ronaldo.", {"Vrai", "Faux"}, 1, 2},
        {"Qui a marqué le plus de buts en Ligue des champions?", {"Cristiano Ronaldo", "Lionel Messi", "Raul", "Robert Lewandowski"}, 0, 1}
    };

    // Évaluer les réponses de l'utilisateur
    evaluerReponses(questions, 3);

    return 0;
}
