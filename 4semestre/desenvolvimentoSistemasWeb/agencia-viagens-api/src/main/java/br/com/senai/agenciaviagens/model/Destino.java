package br.com.senai.agenciaviagens.model;

import jakarta.validation.constraints.NotBlank;

import java.util.ArrayList;
import java.util.List;

public class Destino {

    private Long id;

    @NotBlank(message = "O nome do destino e obrigatorio")
    private String nome;

    @NotBlank(message = "A localizacao do destino e obrigatoria")
    private String localizacao;

    private String descricao;

    private Integer hoteisDisponiveis = 0;

    private List<String> atividadesTuristicas = new ArrayList<>();

    private List<Integer> avaliacoes = new ArrayList<>();

    public Destino() {
}

public Destino(Long id, String nome, String localizacao, String descricao,
                Integer hoteisDisponiveis, List<String> atividadesTuristicas) {
    this.id = id;
    this.nome = nome;
    this.localizacao = localizacao;
    this.descricao = descricao;
    this.hoteisDisponiveis = hoteisDisponiveis;
    this.atividadesTuristicas = atividadesTuristicas != null ? atividadesTuristicas : new ArrayList<>();
  }

public double getMediaAvaliacoes() {
    if (avaliacoes.isEmpty()) {
        return 0.0;
    }
    double soma = 0;
    for (int nota : avaliacoes) {
        soma += nota;
    }
    return soma / avaliacoes.size();
}

public int getQuantidadeAvaliacoes() {
    return avaliacoes.size();
  }

  public Long getId() {
    return id;
}

public void setId(Long id) {
    this.id = id;
}

public String getNome() {
    return nome;
}

public void setNome(String nome) {
    this.nome = nome;
}

public String getLocalizacao() {
    return localizacao;
}

public void setLocalizacao(String localizacao) {
    this.localizacao = localizacao;
}

public String getDescricao() {
    return descricao;
}

public void setDescricao(String descricao) {
    this.descricao = descricao;
}

public Integer getHoteisDisponiveis() {
    return hoteisDisponiveis;
}

public void setHoteisDisponiveis(Integer hoteisDisponiveis) {
    this.hoteisDisponiveis = hoteisDisponiveis;
}

public List<String> getAtividadesTuristicas() {
    return atividadesTuristicas;
}

public void setAtividadesTuristicas(List<String> atividadesTuristicas) {
    this.atividadesTuristicas = atividadesTuristicas;
}

public List<Integer> getAvaliacoes() {
    return avaliacoes;
}

public void setAvaliacoes(List<Integer> avaliacoes) {
    this.avaliacoes = avaliacoes;
  }
}
