#!/bin/bash

TESTES=2
THREADS=10
TEMPO=3000000
THREADS_INC=10
TEMPO_INC=200000
ARQUIVO_THREADS=defaultSyncThreads  #deve ser definido o arquivo de teste com mudança de threads
ARQUIVO_TEMPO=defaultSyncTempo # deve ser definido o arquivo de testes com mudança de tempo


rm $ARQUIVO_THREADS   #limpa o arquivo
for((i = 1; i <= $TESTES; ++i))
{
   ./main $THREADS $TEMPO >> $ARQUIVO_THREADS;
   THREADS=$((THREADS + THREADS_INC))
}
THREADS=10



rm $ARQUIVO_TEMPO   #limpa o arquivo
for((i = 1; i <= $TESTES; ++i))
{
   ./main $THREADS $TEMPO >> $ARQUIVO_TEMPO;
   TEMPO=$((TEMPO + TEMPO_INC))
}
TEMPO=3000000

