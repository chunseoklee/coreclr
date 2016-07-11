Name:		coreclr
Version:	0.0.1
Release:	1
Summary:	Microsoft .NET Runtime, Coreclr
Group:		Development/Languages
License:	Apache-2.0
URL:		http://github.com/dotnet/coreclr
Source0:	%{name}-%{version}.tar.gz

BuildRequires:	cmake
BuildRequires:	llvm = 3.5
BuildRequires:	clang = 3.5
BuildRequires:	lldb = 3.6
BuildRequires:	lldb-dev = 3.6
BuildRequires:	libunwind libunwind-devel
BuildRequires:	gettext
BuildRequires:	libicu-devel
BuildRequires:	lttng-ust-devel
BuildRequires:	libopenssl-devel
BuildRequires:	libuuid-devel

# This may become problematic
BuildRequires:	libcurl-devel 
#BuildRequires:	libcurl4-openssl-dev

BuildRequires;	mono-core
BuildRequires;	mono-compiler


%description
The CoreCLR repo contains the complete runtime implementation for .NET Core. It includes RyuJIT, the .NET GC, native interop and many other components. It is cross-platform, with multiple OS and CPU ports in progress.

%prep
%setup -q -n %{name}-%{version}

%build
./build.sh

%install

%files
