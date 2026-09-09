from flask import Flask, jsonify, request

app = Flask(__name__)

# "Banco de dados" temporário - uma lista em memória
tarefas = [
    {"id": 1, "titulo": "Estudar Flask"},
    {"id": 2, "titulo": "Configurar a AWS"}
]

# Endpoint GET - lista todas as tarefas
@app.route("/tarefas", methods=["GET"])
def listar_tarefas():
    return jsonify(tarefas)

# Endpoint POST - cadastra uma nova tarefa
@app.route("/tarefas", methods=["POST"])
def cadastrar_tarefa():
    dados = request.get_json()
    nova_tarefa = {
        "id": len(tarefas) + 1,
        "titulo": dados["titulo"]
    }
    tarefas.append(nova_tarefa)
    return jsonify(nova_tarefa), 201

if __name__ == "__main__":
    app.run(debug=True)