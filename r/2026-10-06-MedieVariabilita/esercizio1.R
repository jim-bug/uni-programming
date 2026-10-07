# Autore: Ignazio Leonardo Calogero Sperandeo
# Data: 2026-10-07
# Consegna: Rif. README.md
# by jimbug // :)


# Importazione del dataset
dati <- read.csv2("Cpus_data.csv")

# Punto 1: Media, mediana e istogramma di Recommended_Customer_Price
media_price <- mean(
  dati$Recommended_Customer_Price,
  na.rm = TRUE
)

mediana_price <- median(
  dati$Recommended_Customer_Price,
  na.rm = TRUE
)


hist(
  dati$Recommended_Customer_Price,
  main = "Istogramma del Prezzo Consigliato",
  xlab = "Recommended Customer Price",
  ylab = "Frequenza",
  col = "lightblue"
)

# Punto 2: Percentili, classi e frequenze cumulate
percentili <- quantile(
  dati$Recommended_Customer_Price,
  probs = c(0, 0.10, 0.22, 0.40, 0.75, 0.99, 1),
  na.rm = TRUE
)

# Suddivisione in classi
classi <- cut(
  dati$Recommended_Customer_Price,
  breaks = percentili,
  include.lowest = TRUE
)

freq_ass <- table(classi)
n <- sum(freq_ass)

freq_rel <- freq_ass / n
freq_ass_cumu <- cumsum(freq_ass)
freq_rel_cumu <- cumsum(freq_rel)

distribuzione_classi <- cbind(
  FA = freq_ass,
  FR = freq_rel,
  FAC = freq_ass_cumu,
  FRC = freq_rel_cumu
)


# Punto 3: Confronto tra media originale e media della distribuzione in classi
mean_default <- mean(
  dati$Recommended_Customer_Price,
  na.rm = TRUE
)

punti_medi <- (
  percentili[-length(percentili)] +
    percentili[-1]
) / 2

mean_class <- sum(punti_medi * freq_ass) / n


# Punto 4: Boxplot condizionato a Product_Collection
boxplot(
  dati$Recommended_Customer_Price ~ dati$Product_Collection,
  main = "Boxplot Prezzo per Collezione Prodotto",
  xlab = "Product Collection",
  ylab = "Price",
  col = "lightgreen"
)

# Punto 5: Varianza e coefficienti di variazione
var_memory <- var(
  dati$Max_Memory_Size,
  na.rm = TRUE
)

var_band <- var(
  dati$Max_Memory_Bandwidth,
  na.rm = TRUE
)

cv_memory <- (
  sd(dati$Max_Memory_Size, na.rm = TRUE) /
    mean(dati$Max_Memory_Size, na.rm = TRUE)
) * 100

cv_band <- (
  sd(dati$Max_Memory_Bandwidth, na.rm = TRUE) /
    mean(dati$Max_Memory_Bandwidth, na.rm = TRUE)
) * 100

# Punto 6: Eterogeneità di Cache_Type
fa_cache <- table(dati$Cache_Type)
fr_cache <- prop.table(fa_cache)

# Indice di Gini assoluto
gini <- 1 - sum(fr_cache^2)


# Valore massimo teorico
m <- length(fa_cache)
gini_max <- (m - 1) / m

# Indice di Gini normalizzato
gini_norm <- gini / gini_max