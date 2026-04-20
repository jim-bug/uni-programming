FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        verilator \
        make \
        g++ \
        perl \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -m -u 1000 -s /bin/bash simuser

WORKDIR /work
USER simuser
ENTRYPOINT ["bash", "-lc", "if [[ ! -f soluzione1.sv || ! -f tb_soluzione1.sv ]]; then echo 'Errore: esegui dalla cartella esercizio con soluzione1.sv e tb_soluzione1.sv'; exit 1; fi; tb_module=$(grep -Eo '^module[[:space:]]+[A-Za-z_][A-Za-z0-9_]*' tb_soluzione1.sv | awk '{print $2}' | head -1 | tr -d ';'); if [[ -z \"$tb_module\" ]]; then echo 'Errore: top module del testbench non trovato'; exit 1; fi; verilator --binary --timing --top-module \"$tb_module\" soluzione1.sv tb_soluzione1.sv; ./obj_dir/V\"$tb_module\""]

