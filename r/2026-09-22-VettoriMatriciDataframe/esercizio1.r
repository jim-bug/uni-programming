# Autore: Ignazio Leonardo Calogero Sperandeo
# Data: 2026-09-22
# Consegna: Rif. README.md
# by jimbug // :)

# creazione della sequenza numerica
s1 <- seq(1, 100, 5)
length(s1)

# s2 <- array(c(rep("M", 10), rep("F", 10)))
# s2 <- c(rep("M", 10), rep("F", 10))
s2 <- rep(c("M", "F"), each = 10)       # ulteriore modo per realizzare una sequenza non numerica con ripetizioni note

# creazione e verifica di una matrice
M1 <- cbind(s1, s2)
is.matrix(M1)

# creazione di un df sulla base della matrice precedente
M1.df <- data.frame(
  eta = s1,
  sesso = s2
)

colnames(M1) <- c("eta", "sesso")

# selezione di tutte le unità che presentano come eta un valore <= 50
M1.df[M1.df$eta <= 50, ]
