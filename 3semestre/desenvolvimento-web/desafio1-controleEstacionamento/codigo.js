  //  VAGAS ESTÁTICAS
const VAGAS_CONFIG = {
  'Andar Térreo': [1,2,3,4,5,6,7,8,9,10],
  '1º Subsolo':  [11,12,13,14,15,16,17,18,19,20],
  '2º Subsolo':  [21,22,23,24,25,26,27,28,29,30],
};

  //  ARMAZENAMENTO
function getVagas() {
  const saved = localStorage.getItem('parkcontrol_vagas');
  if (saved) return JSON.parse(saved);

  // INICIA VAGAS LIVRES
  const vagas = {};
  Object.values(VAGAS_CONFIG).flat().forEach(n => {
    vagas[n] = { num: n, status: 'livre', reserva: null };
  });
  localStorage.setItem('parkcontrol_vagas', JSON.stringify(vagas));
  return vagas;
}

function saveVagas(vagas) {
  localStorage.setItem('parkcontrol_vagas', JSON.stringify(vagas));
}

function getReservas() {
  return JSON.parse(localStorage.getItem('parkcontrol_reservas') || '[]');
}

function saveReservas(lista) {
  localStorage.setItem('parkcontrol_reservas', JSON.stringify(lista));
}

  //  NAVEGAÇÃO
function showScreen(name) {
  document.querySelectorAll('.screen').forEach(s => s.classList.remove('active'));
  document.querySelectorAll('.nav-btn').forEach(b => b.classList.remove('active'));
  document.getElementById('screen-' + name).classList.add('active');
  document.querySelectorAll('.nav-btn')[name === 'cadastro' ? 0 : 1].classList.add('active');
  if (name === 'listagem') renderListing();
  if (name === 'cadastro') populateVagaSelect();
}

  //  POPULA SELECT DE VAGAS DISPONÍVEIS
function populateVagaSelect() {
  const select = document.getElementById('vaga');
  const vagas  = getVagas();
  select.innerHTML = '<option value="">Selecione uma vaga disponível</option>';

  Object.entries(VAGAS_CONFIG).forEach(([andar, nums]) => {
    const group = document.createElement('optgroup');
    group.label = andar;
    nums.forEach(n => {
      const v = vagas[n];
      if (v.status === 'livre') {
        const opt = document.createElement('option');
        opt.value = n;
        opt.textContent = `Vaga ${n}`;
        group.appendChild(opt);
      }
    });
    if (group.children.length) select.appendChild(group);
  });
}

  //  VALIDAÇÃO
function clearErrors() {
  document.querySelectorAll('.field-error').forEach(e => e.textContent = '');
  document.querySelectorAll('input, select').forEach(e => e.classList.remove('error'));
}

function setError(fieldId, msg) {
  const el = document.getElementById(fieldId);
  const err = document.getElementById('err-' + fieldId);
  el.classList.add('error');
  if (err) err.textContent = msg;
  return false;
}

function validarPlaca(placa) {
  // Novo Modelo: ABC1D23 | Modelo Antigo: ABC-1234
  return /^[A-Z]{3}[0-9][A-Z0-9][0-9]{2}$/.test(placa.replace('-','').toUpperCase());
}

function validateForm(dados) {
  let valid = true;
  clearErrors();

  const placa = dados.placa.replace(/\s/g,'').toUpperCase();
  if (!placa) { setError('placa','Campo obrigatório.'); valid = false; }
  else if (!validarPlaca(placa)) { setError('placa','Placa inválida. Use ABC-1234 ou ABC1D23.'); valid = false; }

  if (!dados.modelo.trim()) { setError('modelo','Campo obrigatório.'); valid = false; }
  if (!dados.cor)           { setError('cor','Selecione a cor.'); valid = false; }
  if (!dados.nome.trim())   { setError('nome','Campo obrigatório.'); valid = false; }
  if (!dados.apartamento.trim()) { setError('apartamento','Campo obrigatório.'); valid = false; }
  if (!dados.bloco)         { setError('bloco','Selecione o bloco.'); valid = false; }

  if (!dados.vaga) {
    setError('vaga','Selecione uma vaga.'); valid = false;
  } else {
    const vagas = getVagas();
    const v = vagas[dados.vaga];
    if (!v) { setError('vaga','Vaga inexistente.'); valid = false; }
    else if (v.status !== 'livre') { setError('vaga','Esta vaga já está ocupada.'); valid = false; }
  }

  return valid;
}

  //  ENVIO FORMULÁRIO
document.getElementById('formCadastro').addEventListener('submit', function(e) {
  e.preventDefault();

  const dados = {
    placa:       document.getElementById('placa').value.replace('-','').toUpperCase(),
    modelo:      document.getElementById('modelo').value.trim(),
    cor:         document.getElementById('cor').value,
    nome:        document.getElementById('nome').value.trim(),
    apartamento: document.getElementById('apartamento').value.trim(),
    bloco:       document.getElementById('bloco').value,
    vaga:        Number(document.getElementById('vaga').value),
    dataHora:    new Date().toLocaleString('pt-BR'),
  };

  if (!validateForm(dados)) return;

  // SALVA RESERVA
  const reservas = getReservas();
  reservas.push(dados);
  saveReservas(reservas);

  // ATUALIZAR STATUS DA VAGA
  const vagas = getVagas();
  vagas[dados.vaga].status  = 'ocupada';
  vagas[dados.vaga].reserva = dados;
  saveVagas(vagas);

  // CONFIRMAÇÃO DA RESERVA NO CONSOLE
  console.log('✅ Reserva cadastrada:', dados);

  // POPUP DE CONFIRMAÇÃO
  document.getElementById('popupDetail').innerHTML = `
    <span>Proprietário:</span> <strong>${dados.nome}</strong>\n
    <span>Apartamento:</span>  <strong>${dados.apartamento} — Bloco ${dados.bloco}</strong>\n
    <span>Veículo:</span>      <strong>${dados.modelo} (${dados.cor})</strong>\n
    <span>Placa:</span>        <strong>${dados.placa}</strong>\n
    <span>Vaga:</span>         <strong>Nº ${dados.vaga}</strong>\n
    <span>Data/Hora:</span>    <strong>${dados.dataHora}</strong>
  `.replace(/\n/g,'<br>');

  document.getElementById('popup').classList.add('show');

  // RESET FORMULÁRIO E ATUALIZA SELECT
  document.getElementById('formCadastro').reset();
  populateVagaSelect();
});

function closePopup() {
  document.getElementById('popup').classList.remove('show');
}

  //  LISTA DE RENDERIZAÇÃO
function renderListing() {
  const vagas = getVagas();
  const todas = Object.values(vagas);
  const total = todas.length;
  const livres = todas.filter(v => v.status === 'livre').length;
  const ocupadas = total - livres;

  document.getElementById('statsRow').innerHTML = `
    <div class="stat-card">
      <div class="stat-dot total"></div>
      <div><div class="stat-num">${total}</div><div class="stat-label">Total de Vagas</div></div>
    </div>
    <div class="stat-card">
      <div class="stat-dot free"></div>
      <div><div class="stat-num" style="color:var(--free)">${livres}</div><div class="stat-label">Disponíveis</div></div>
    </div>
    <div class="stat-card">
      <div class="stat-dot occup"></div>
      <div><div class="stat-num" style="color:var(--occupied)">${ocupadas}</div><div class="stat-label">Ocupadas</div></div>
    </div>
  `;

  const map = document.getElementById('parkingMap');
  map.innerHTML = '';

  Object.entries(VAGAS_CONFIG).forEach(([andar, nums]) => {
    const row = document.createElement('div');
    row.className = 'parking-row';
    row.innerHTML = `<div class="row-label">${andar}</div><div class="slots-grid"></div>`;
    map.appendChild(row);

    const grid = row.querySelector('.slots-grid');
    nums.forEach(n => {
      const v = vagas[n];
      const isFree = v.status === 'livre';
      const slot = document.createElement('div');
      slot.className = `slot ${isFree ? 'free' : 'occupied'}`;

      if (!isFree && v.reserva) {
        const r = v.reserva;
        slot.setAttribute('data-tip', `${r.nome}\n${r.modelo} · ${r.cor}\nPlaca: ${r.placa}\nApto ${r.apartamento} · Bloco ${r.bloco}`);
        slot.addEventListener('click', () => openModal(n));
      }

      slot.innerHTML = `
        <div class="slot-icon">${isFree ? '🟢' : '🔴'}</div>
        <div class="slot-num">${n}</div>
        <div class="slot-status">${isFree ? 'LIVRE' : 'OCUP.'}</div>
        ${!isFree && v.reserva ? `<div class="slot-plate">${v.reserva.placa}</div>` : ''}
      `;
      grid.appendChild(slot);
    });
  });
}

  //  RESERVA TEMPORÁRIA DE VAGA SELECIONADA
let vagaAtiva = null;

function openModal(numVaga) {
  const vagas = getVagas();
  const v = vagas[numVaga];
  if (!v || v.status !== 'ocupada') return;

  vagaAtiva = numVaga;

  // PREENCHE VAGA
  document.getElementById('modalVagaTitulo').textContent = `Vaga ${numVaga}`;
  const r = v.reserva;
  document.getElementById('modalVagaInfo').innerHTML = `
    <span>Proprietário:</span> <strong>${r.nome}</strong><br>
    <span>Apartamento:</span>  <strong>${r.apartamento} — Bloco ${r.bloco}</strong><br>
    <span>Veículo:</span>      <strong>${r.modelo} (${r.cor})</strong><br>
    <span>Placa:</span>        <strong>${r.placa}</strong><br>
    <span>Desde:</span>        <strong>${r.dataHora}</strong>
  `;

  // RESETA TRANSFERÊNCIA
  document.getElementById('transferSection').style.display = 'none';
  document.getElementById('btnTransferir').textContent = '⇄ Transferir para outra vaga';

  // popula select de vagas livres (exceto a atual)
  const selectNova = document.getElementById('selectNovaVaga');
  selectNova.innerHTML = '<option value="">Selecione a vaga de destino</option>';
  Object.entries(VAGAS_CONFIG).forEach(([andar, nums]) => {
    const group = document.createElement('optgroup');
    group.label = andar;
    nums.forEach(n => {
      if (vagas[n].status === 'livre') {
        const opt = document.createElement('option');
        opt.value = n;
        opt.textContent = `Vaga ${n}`;
        group.appendChild(opt);
      }
    });
    if (group.children.length) selectNova.appendChild(group);
  });

  document.getElementById('modalAcoes').classList.add('show');
}

function closeModal() {
  document.getElementById('modalAcoes').classList.remove('show');
  vagaAtiva = null;
}

function toggleTransfer() {
  const section = document.getElementById('transferSection');
  const btn = document.getElementById('btnTransferir');
  const aberto = section.style.display !== 'none';

  if (aberto) {
    section.style.display = 'none';
    btn.textContent = '⇄ Transferir para outra vaga';
  } else {
    section.style.display = 'block';
    btn.textContent = '✔ Confirmar Transferência';
    // segunda vez que clica executa a transferência
    btn.onclick = confirmarTransferencia;
  }
}

function confirmarLiberar() {
  if (!vagaAtiva) return;
  if (!confirm(`Confirma a liberação da vaga ${vagaAtiva}? O registro da reserva será removido.`)) return;

  const vagas = getVagas();
  const reservas = getReservas();

  // remove da lista de reservas
  const idx = reservas.findIndex(r => r.vaga === vagaAtiva);
  if (idx !== -1) reservas.splice(idx, 1);
  saveReservas(reservas);

  // libera vaga
  vagas[vagaAtiva].status  = 'livre';
  vagas[vagaAtiva].reserva = null;
  saveVagas(vagas);

  console.log(`🟢 Vaga ${vagaAtiva} liberada.`);

  closeModal();
  renderListing();
  populateVagaSelect();
  showToast(`✔ Vaga ${vagaAtiva} liberada com sucesso!`, 'success');
}

function confirmarTransferencia() {
  const novaVaga = Number(document.getElementById('selectNovaVaga').value);
  if (!novaVaga) { showToast('Selecione a vaga de destino.', 'info'); return; }

  const vagas = getVagas();
  const reservas = getReservas();

  if (vagas[novaVaga].status !== 'livre') {
    showToast('A vaga selecionada não está mais disponível.', 'info');
    return;
  }

  // move reserva
  const reserva = { ...vagas[vagaAtiva].reserva, vaga: novaVaga, dataHora: new Date().toLocaleString('pt-BR') };

  // atualiza lista de reservas
  const idx = reservas.findIndex(r => r.vaga === vagaAtiva);
  if (idx !== -1) reservas[idx] = reserva;
  saveReservas(reservas);

  // libera vaga antiga, ocupa nova
  vagas[vagaAtiva].status  = 'livre';
  vagas[vagaAtiva].reserva = null;
  vagas[novaVaga].status   = 'ocupada';
  vagas[novaVaga].reserva  = reserva;
  saveVagas(vagas);

  console.log(`🔄 Transferência: vaga ${vagaAtiva} → vaga ${novaVaga}`, reserva);

  closeModal();
  renderListing();
  populateVagaSelect();
  showToast(`⇄ Transferido: Vaga ${vagaAtiva} → Vaga ${novaVaga}`, 'info');

  // reset do botão transferir para próxima abertura
  document.getElementById('btnTransferir').onclick = toggleTransfer;
}

  //  TEMPORIZADOR
let toastTimer = null;
function showToast(msg, type = 'success') {
  const t = document.getElementById('toast');
  t.textContent = msg;
  t.className = `toast ${type} show`;
  clearTimeout(toastTimer);
  toastTimer = setTimeout(() => t.classList.remove('show'), 3000);
}

  //  INICIALIZAÇÃO
getVagas();          // inicializa se necessário
populateVagaSelect();   // preenche select na tela de cadastro
showScreen('cadastro'); // mostra tela inicial