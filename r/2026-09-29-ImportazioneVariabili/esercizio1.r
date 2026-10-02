# Autore: Ignazio Leonardo Calogero Sperandeo
# Data: 2026-09-29
# Consegna: Rif. README.md
# by jimbug // :)

dati <- read.table("DatiStat1.txt", header = TRUE)
str(dati)     # controllo la struttura del file in input

alt <- dati$Altezza

livelli <- c("Elementare", "Media", "Diploma", "Laurea")

dati$GIP <- factor(dati$GIP, levels = livelli, ordered = TRUE)    # grado istruzione padre, ordinato secondo la variabile livelli
dati$GIM <- factor(dati$GIM, levels = livelli, ordered = TRUE)    # grado istruzione madre, ordinato secondo la variabile livelli

dati[dati$Diploma == "Scientifico", ]

which(dati$Altezza < 168)

dati[dati$GIP == "Laurea" & dati$GIM == "Laurea", ]

