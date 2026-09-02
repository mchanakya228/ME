%% INFINITE POTENTIAL WELL — full numerical treatment
% Particle in a 1D box of width L, walls at x=0 and x=L.
%
% psi_n(x) = sqrt(2/L) * sin(n*pi*x/L)
% E_n      = n^2 * pi^2 * hbar^2 / (2*m*L^2)
%
% This script:
%   1) plots psi_n(x) and |psi_n(x)|^2 for several n
%   2) verifies normalization numerically:  ∫|psi|^2 dx = 1
%   3) verifies orthogonality between different n
%   4) computes <x> and <p> numerically and compares to theory
%   5) prints the quantized energy levels

clear; clc; close all;

%% --- Physical / well parameters ---
hbar = 1.054571817e-34;   % J*s
m    = 9.10938370e-31;    % kg (electron mass, just as an example)
L    = 1e-9;              % well width, 1 nm

%% --- Spatial grid ---
N_points = 2000;
x = linspace(0, L, N_points)';   % column vector
dx = x(2) - x(1);

%% --- Define psi_n(x) as a function handle ---
% (real-valued for the infinite well, so psi* = psi)
psi = @(n, x) sqrt(2/L) * sin(n*pi*x/L);

%% --- 1) Plot wavefunctions and probability densities ---
n_list = [1 2 3 4];

figure('Name','Wavefunctions');
hold on;
for n = n_list
    plot(x/L, psi(n,x)*sqrt(L), 'LineWidth', 1.5, ...
        'DisplayName', sprintf('n = %d', n));
end
xlabel('x / L'); ylabel('\psi_n (scaled)');
title('Infinite Well Wavefunctions');
legend show; grid on;

figure('Name','Probability Densities');
hold on;
for n = n_list
    plot(x/L, abs(psi(n,x)).^2 * L, 'LineWidth', 1.5, ...
        'DisplayName', sprintf('n = %d', n));
end
xlabel('x / L'); ylabel('|\psi_n|^2 (scaled)');
title('Probability Densities  |\psi_n(x)|^2');
legend show; grid on;
% Notice: n=1 peaks in the middle; n=2 has a node (zero) exactly at x = L/2.

%% --- 2) Verify normalization: ∫|psi_n|^2 dx should equal 1 ---
fprintf('--- Normalization check ---\n');
for n = n_list
    psi_n = psi(n, x);
    norm_check = trapz(x, conj(psi_n) .* psi_n);  % conj() here for generality
    fprintf('n=%d : integral of |psi|^2 dx = %.6f (should be 1)\n', n, norm_check);
end

%% --- 3) Verify orthogonality: ∫ psi_n* psi_m dx should be 0 for n ~= m ---
fprintf('\n--- Orthogonality check (n=1 vs n=2) ---\n');
overlap = trapz(x, conj(psi(1,x)) .* psi(2,x));
fprintf('integral of psi_1* * psi_2 dx = %.2e (should be ~0)\n', overlap);

%% --- 4) Expectation values <x> and <p>, computed numerically ---
% <x> = ∫ psi* x psi dx
% <p> = ∫ psi* (-i*hbar * d/dx) psi dx   -> use a numerical derivative

fprintf('\n--- Expectation values ---\n');
for n = n_list
    psi_n = psi(n, x);

    % <x>: sandwich the position operator (just "multiply by x")
    x_expect = trapz(x, conj(psi_n) .* x .* psi_n);

    % <p>: sandwich the momentum operator -i*hbar*d/dx
    dpsi_dx = gradient(psi_n, dx);              % numerical d(psi)/dx
    p_expect = trapz(x, conj(psi_n) .* (-1i*hbar*dpsi_dx));

    fprintf('n=%d : <x> = %.4e m  (theory: L/2 = %.4e m) | <p> = %.2e kg*m/s (theory: 0)\n', ...
        n, real(x_expect), L/2, real(p_expect));
end

%% --- 5) Quantized energy levels ---
fprintf('\n--- Energy levels ---\n');
n_energy = 1:5;
E_n = (n_energy.^2 * pi^2 * hbar^2) / (2*m*L^2);   % Joules
E_n_eV = E_n / 1.602176634e-19;                     % convert to eV

for k = 1:length(n_energy)
    fprintf('E_%d = %.4f eV\n', n_energy(k), E_n_eV(k));
end

figure('Name','Energy Levels');
hold on;
for k = 1:length(n_energy)
    plot([0 1], [E_n_eV(k) E_n_eV(k)], 'LineWidth', 2);
    text(1.05, E_n_eV(k), sprintf('n=%d', n_energy(k)));
end
ylabel('Energy (eV)');
title('Quantized Energy Levels — Infinite Well');
xlim([0 1.3]); set(gca,'XTick',[]); grid on;