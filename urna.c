#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int codigo;
  int voto;
  struct no *prox;
}Eleitor;

Eleitor *criarEleitor(){
    return NULL;
}

typedef struct no2{
    int numero;
    char partido;
    int votos;
    struct no2 *prox;
}Candidato;

Candidato *criarCandidato(){
    return NULL;
}

Eleitor *insereEleitor(Eleitor *eleitor, int v){
  Eleitor *novo = (Eleitor*)malloc(sizeof(Eleitor));
  novo->codigo = v;
  novo->prox = eleitor;
  novo->voto = 0;
  return novo;
}

Candidato *insereCandidato(Candidato *candidato, int numero, char partido[]){
  Candidato *novo = (Candidato*)malloc(sizeof(Candidato));
  novo->numero = numero;
  novo->partido = partido;
  novo->prox = candidato;
  novo->votos = 0;
  return novo;
}

void mostrarEleitores(Eleitor *eleitor){
  Eleitor *p;
  for(p = eleitor; p != NULL; p = p->prox){
    printf("{\n   Codigo: %d\n   Voto: %d\n}\n\n", p->codigo, p->voto);
  }
}

void mostrarCandidatos(Candidato *candidato){
  Candidato *p;
  for(p = candidato; p != NULL; p = p->prox){
    printf("{\n    Numero: %d\nPartido: %c\nVotos: %d\n}\n", p->numero, p->partido, p->votos);
  }
}

Eleitor *buscarEleitor(Eleitor *eleitor, int cod){
  Eleitor *p = NULL ;
  for(p = eleitor; p != NULL; p = p->prox){
    if(p->codigo == cod){
      printf("{\n\tCodigo: %d\n\tVoto: %d\n}\n\n", p->codigo, p->voto);
      return p;
    }
  }
  printf("Nao encontrado!");
  return NULL;
}

Candidato *buscarCandidato(Candidato *candidato, int numero){
  Candidato *p = NULL ;
  for(p = candidato; p != NULL; p = p->prox){
    if(p->numero == numero){
      printf("{\n\tNumero: %d\n\tPartido: %c\n\tVotos: %d\n}\n", p->numero, p->partido, p->votos);
      return p;
    }
  }
  printf("Nao encontrado!");
  return NULL;
}

void votar(Eleitor *eleitor, Candidato *candidato){
    int cod, num;
    Eleitor *e;
    Candidato *c;
    printf("insira seu codigo de eleitor: ");
    scanf("%d", &cod);
    if(buscarEleitor(eleitor, cod) != NULL){
      printf("Digite o numero do seu candidato: ");
      scanf("%d", &num);
      if (buscarCandidato(candidato, num) != NULL){
        for(e = eleitor; e != NULL; e = e->prox){
          if(e->codigo == cod){
          e->voto = num;
          }
        }
        for(c = candidato; c != NULL; c = c->prox){
          if(c->numero == num){
            c->votos++;
          }
        }
      }else{
        printf("Cadidato nao encontrado!");
      }
    }else{
      printf("Eleitor nao encontrado!");
    }
}


int main(void) {
  Eleitor *eleitor;
  eleitor = criarEleitor();

  Candidato *candidato;
  candidato = criarCandidato();

  //Gerando Candidatos!
  for (int j = 0; j <= 20; j++){
    if(j <= 4){
        candidato = insereCandidato(candidato, (j + 1101), 'PBA');
    }else if((j >= 5)&&(j <= 8)){
        candidato = insereCandidato(candidato, (j + 2196), 'PBB');
    }else if((j >= 9)&&(j <= 12)){
        candidato = insereCandidato(candidato, (j + 3292), 'PBC');
    }else if((j >= 13)&&(j <= 16)){
        candidato = insereCandidato(candidato, (j + 4388), 'PBD');
    }else{
        candidato = insereCandidato(candidato, (j + 5484), 'PBE');
    }
  }
  
  //Gerando Eleitores!
  /*for(int i = 1; i <= 200; i++){
    eleitor = insereEleitor(eleitor, i);
  }*/

  int menu, cod, numero, eleit, candNum;
  char candPart;
  do{
    printf("\n\t1 - Votar\n\t2 - Inserir Eleitor\n\t3 - Inserir Candidato\n\t4 - Buscar Eleitor\n\t5 - Buscar Candidato\n\t6 - Mostar Eleitores\n\t7 - Mostar Candidatos\n\t0 - Sair\n");
    scanf("%d", &menu);

    switch(menu){
        case 1:
            votar(eleitor, candidato);
            break;
        case 2:
            printf("Insira o codigo do eleitor a ser adicionado: ");
            scanf("%d", &eleit);
            eleitor = insereEleitor(eleitor, eleit);
            break;
        case 3:
            printf("Insira o numero e o partido do candidato a ser adicionado: ");
            scanf("%d %c", &candNum, &candPart);
            candidato = insereCandidato(candidato, candNum, candPart);
            break;
        case 4:
            printf("Informe o codigo do eleitor: ");
            scanf("%d", &cod);
            buscarEleitor(eleitor, cod);
            break;
        case 5:
            printf("Informe o numero do cadidato: ");
            scanf("%d", &numero);
            buscarCandidato(candidato, numero);
            break;
        case 6:
            mostrarEleitores(eleitor);
            break;
        case 7:
            mostrarCandidatos(candidato);
            break;
    }
  }while(menu != 0);

}