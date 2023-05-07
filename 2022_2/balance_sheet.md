# Problem

Metal Platforms, Inc. (a.k.a. Metal), formerly a mining company, now offers a service to facilitate sheet metal sales. It has $N$ clients, where client $i$ wants to buy only on day $A_i$​ for $\$X_i$​ per sheet, and sell only on a strictly later day $B_i$​ for $\$Y_i$​ per sheet.

Client $i$ can sell to client $j$ if $B_i = A_j$​, and if client $j$ is buying for a strictly higher price than what client $i$ is selling for, i.e. if $X_j > Y_i$​. If Metal facilitates the sale, they earn a profit of $\$(X_j - Y_i)$.

A path is any ordered sequence of clients where each client can sell to the next. A path's profit is the total profit that Metal would make if a single sheet were theoretically sold along it.

Metal would like to know the total profit across the $K$ most profitable paths (or across all distinct paths if there are fewer than $K$). Since this may be large, please print it modulo $1{,}000{,}000{,}007$.
