#!/usr/bin/env ruby
# ***************************************************************************** #
#                                                                               #
#                                                          :::      ::::::::    #
#    vm_beta.rb [ version 1.1 ]                          :+:      :+:    :+:    #
#                                                      +:+ +:+         +:+      #
#    By: hcao, abanlin                               +#+  +:+       +#+         #
#                                                  +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 14:37:26 by abanlin            #+#    #+#              #
#    Updated: 2013/11/20 14:37:26 by abanlin           ###   ########.fr        #
#                                                                               #
# ***************************************************************************** #

require 'timeout'
require 'open3'

class Plateau
	def initialize(map_path, seed, trace)
		if (seed < 0)
			seed = Random.new_seed % 10000
		end
		srand(seed)
		trace.trace_msg("seed = #{seed.to_s}\n")
		begin
		@map_content = File.read(map_path)
		rescue
			puts "error:"
			puts "can not read the file"
			exit (-1)
		end
		begin
		@map_row = @map_content.count("\n")
		rescue
			puts "error:"
			puts "wrong map file"
			exit (-2)
		end
		@map_col = -1
		(@map_table = @map_content.split("\n")).each do |string|
			if @map_col == -1
				@map_col = string.length
			elsif @map_col != string.length
				begin
					throw "Maperror"
				rescue
					puts "error:"
					puts "wrong map file"
					exit (-5)
				end
			end
		end
	end

	def gene_piece()

		if (rand(100) == 0)
			ratio = rand(100)
			@piece_row = rand((@map_row - 1) * ratio / 100) + 1
			ratio = rand(100)
			@piece_col = rand((@map_col - 1) * ratio / 100) + 1
		else
			@piece_row = rand((@map_row - 1) / 5) + 1
			@piece_col = rand((@map_col - 1) / 5) + 1
		end

		@piece_row = @piece_row.to_i
		@piece_col = @piece_col.to_i
		@piece_content = ""
		for i in 0..(@piece_row * @piece_col)
			@piece_content += "."
		end
		@piece_content[(y = rand(@piece_row)) * @piece_col + (x = rand(@piece_col))] = '*'

		p = 0
		i = 4
		if (y + 1 < @piece_row && rand(i) == 1)
			@piece_content[(y + 1) * @piece_col + (x)] = '*'
			p += 1
		end
		if (x + 1 < @piece_col && rand(i) == 1)
			@piece_content[(y) * @piece_col + (x + 1)] = '*'
			p += 1
		end
		if (x - 1 > 0 && rand(i) == 1)
			@piece_content[(y) * @piece_col + (x - 1)] = '*'
			p += 1
		end
		if (y - 1 > 0 && rand(i) == 1)
			@piece_content[(y - 1) * @piece_col + (x)] = '*'
			p += 1
		end

		i = 4
		if (y + 1 < @piece_row && x + 1 < @piece_col && rand(i) == 1)
			@piece_content[(y + 1) * @piece_col + (x + 1)] = '*'
			p += 1
		end
		if (y - 1 > 0 && x + 1 < @piece_col && rand(i) == 1)
			@piece_content[(y - 1) * @piece_col + (x + 1)] = '*'
			p += 1
		end
		if (y + 1 < @piece_row && x - 1 > 0 && rand(i) == 1)
			@piece_content[(y + 1) * @piece_col + (x - 1)] = '*'
			p += 1
		end
		if (y - 1 > 0 && x - 1 > 0 && rand(i) == 1)
			@piece_content[(y - 1) * @piece_col + (x - 1)] = '*'
			p += 1
		end

		for i in 0..(@piece_row * @piece_col / 2)
			y = rand(@piece_row)
			x = rand(@piece_col)
			if ((y + 1 < @piece_row && @piece_content[(y + 1) * @piece_col + (x)] == "*" ) ||
				(x + 1 < @piece_col && @piece_content[(y) * @piece_col + (x + 1)] == "*" ) ||
				(y - 1 > 0 && @piece_content[(y - 1) * @piece_col + (x)] == "*" ) ||
				(x - 1 > 0 && @piece_content[(y) * @piece_col + (x - 1)] == "*"))
				@piece_content[(y) * @piece_col + (x)] = '*'
				p += 1
			end
		end

		if (p == 0)
			gene_piece()
		end
	end

	def show_mapcontent(fd, piece_char = nil, y = 0, x = 0)
		fd.write "Plateau #{@map_row} #{@map_col}:\n"

		fd.write "    "
		for i in 0..(@map_col - 1)
			fd.write (i % 10).to_s
		end
		fd.write "\n"

		@map_table.each_with_index do |line, row|
			if (row / 100) == 0
				fd.write "0"
			end
			if (row / 10) == 0
				fd.write "0"
			end
			fd.write row.to_s + " "

			if (piece_char == nil || row < y || row >= (y + @piece_row))
				fd.write line + "\n"
			else
				col = 0
				while (col < line.length)
					if (col >= x &&
						col < (x + @piece_col) &&
						@piece_content[(row - y) * @piece_col + (col - x)] == '*')
						fd.write piece_char
					else
						fd.write line[col]
					end
					col += 1
				end
				fd.write "\n"
			end
		end
	end

	def show_piececontent(fd)
		fd.write "Piece #{@piece_row} #{@piece_col}:\n"

		x = 0
		for i in 0..(@piece_row - 1)
			for l in 0..(@piece_col - 1)
				fd.write "#{@piece_content[x]}"
				x = x + 1
			end
			fd.write "\n"
		end
	end

	def piece_char(x, y)
		@piece_content[y * @piece_col + x]
	end

	def check_placement(row, col, char)
		i = 0
		for y in 0..(@piece_row - 1)
			for x in 0..(@piece_col - 1)
				if (y + row >= @map_row || x + col >= @map_col)
					return 2
				end
				if (@map_table[y + row][x + col] != '.' && (tmp = piece_char(x, y)) != '.')
					if (@map_table[y + row][x + col] == char)
						i = i + 1
					else
						return 2
					end
				end
			end
		end
		return i
	end

	def change_data(row, col, char)
		for y in 0..(@piece_row - 1)
			for x in 0..(@piece_col - 1)
				if (piece_char(x, y) == '*')
					@map_table[y + row][x + col] = char
				end
			end
		end
	end

	def small_map()
		if (@map_row < 2 && @map_col < 4) or (@map_row < 4 && @map_col < 2)
			puts "#{$0}: the map is too small"
			exit 21
		end
	end
end

class Player
	attr_accessor :score, :piece_char, :score, :stdin, :live, :file_name

	def initialize(path, char)
		self.file_name = path
		self.piece_char = char
		self.score = 0
		self.live = 1
	end

	def launch()
		begin
			self.stdin, @stdout, @wait_thr = Open3.popen2(@file_name)
			puts "launched #{self.file_name}"
		rescue
			puts "error:"
			puts "bad player"
			exit (-3)
		end
	end

	def mode_interactive()
		self.stdin = STDOUT
		@stdout = STDIN
	end

	def write_to_player(string)
          begin
		self.stdin.write string
          rescue
          end
	end

	def read_from_player()
		begin
			@stdout.readline
		rescue
			return "exit"
		end
	end

	def end_player(trace)
		if (self.live > 0)
			self.live = 0
			if self.stdin != STDOUT
				self.stdin.close
				@stdout.close
				exit_status = @wait_thr.value
				if (exit_status.signaled? && exit_status.termsig == 11)
					trace.trace_msg("#{self.file_name}: Segfault at #{self.score}\n")
					puts("#{self.file_name}: Segfault at #{self.score}\n")
					@segfault = "Segfault"
				elsif (exit_status.signaled? && exit_status.termsig == 10)
					trace.trace_msg("#{self.file_name}: Bus error at #{self.score}\n")
					puts("#{self.file_name}: Bus error at #{self.score}\n")
					@segfault = "Bus error"
				end
			end
		end
	end
	def score_show()
		puts "== #{self.piece_char} fin: " + self.score.to_s
		if @segfault != nil
		   puts "#{self.file_name} #{@segfault}"
		end
	end
end

class Trace
	def initialize(filename = "filler.trace")
		begin
			@file = File.new(filename, File::CREAT|File::TRUNC|File::WRONLY, 0644)
		rescue
			puts "error:"
			puts "can not write in filler.trace"
			exit (-4)
		end
	end

	def trace_msg(msg)
		@file.write(msg)
	end

	def player_win_trace(playername)
		trace_msg("#{playername} won\n")
	end

	def the_end(players)
		if players.count == 2
			if players[0].score > players[1].score
				player_win_trace(players[0].file_name)
			else
				player_win_trace(players[1].file_name)
			end
			trace_msg("Score:\n#{players[0].score.to_s}AGAINST#{players[1].score.to_s}\n")
		end
		@file.close
	end
end

class	Vm_filler
	attr_accessor :map, :player, :challenger, :interactif, :sid, :verbose, :time, :modif_time

	def	initialize(argv = nil)
		self.time = 10
		self.modif_time = 0
		self.map = nil
		self.player = nil
		self.challenger = nil
		self.interactif = 0
		self.verbose = 1
		self.sid = -1
		nmap = Proc.new do |av|
			self.map = av
		end
		user = Proc.new do |av|
			self.player = av
		end
		versus = Proc.new do |av|
			self.challenger = av
		end
		inter = Proc.new do |av|
			self.interactif = 1
		end
		sid_ran = Proc.new do |av|
			self.sid = av.to_i
		end
		verb = Proc.new do |av|
			self.verbose = 0
		end
		time = Proc.new do |av|
			self.modif_time = 1
			self.time = av.to_i
		end
		func = {
			"--file" => nmap,
			"-f" => nmap,
			"--player1" => user,
			"-p1" => user,
			"--player2" => versus,
			"-p2" => versus,
			"--interactive" => inter,
			"-i" => inter,
			"--seed" => sid_ran,
			"-s" => sid_ran,
			"--quiet" => verb,
			"-q" => verb,
			"-t" => time,
			"--time" => time
		}
		argv.each_with_index do |av, i|
			if (func[av])
				func[av].call(argv[i + 1])
			end
		end
	end

	def help
		puts "#{$0}, made by Hcao and Abanlin, version 1.1\n\n"
		puts "Usage: #{$0} -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]\n\n"
		puts "   -t  --time		set timeout in second"
		puts "   -q  --quiet		quiet mode"
		puts "   -i  --interactive	interactive mode(default)"
		puts "   -p1 --player1	use filler binary as a first player"
		puts "   -p2 --player2	use filler binary as a second player"
		puts "   -f  --file		use a map file (required)"
		puts "   -s  --seed		use the seed number (initialization random) (man srand)"
	end

	def version
		$stdout.write "# -------------- VM  version 1.1 ------------- #\n"
		$stdout.write "#                                              #\n"
		$stdout.write "# 42 / filler VM Developped by: Hcao - Abanlin #\n"
		$stdout.write "#                                              #\n"
		$stdout.write "# -------------------------------------------- #\n"
	end
end

def all_lose(players, trace)
	i = 0
	for player in players
		i += player.live
	end
	return i > 0
end

trap("SIGINT") { throw :ctrl_c }

if __FILE__ == $0
	 begin
		catch :ctrl_c do
			begin
			rescue Exception
				puts "exit2"
			end
		end
		init = Vm_filler.new(ARGV)
		if init.map == nil
			init.help
			exit 42
		end
		if init.player == nil
			init.interactif = 1
		end
		if init.interactif == 1 && init.modif_time == 0
			init.time = 0
		end
		@exit_value = 42
		trace = Trace.new
		map = Plateau.new(init.map, init.sid, trace)

		map.small_map

		players = []
		if init.player != nil
			players << Player.new(init.player, 'O')
		end
		if init.challenger != nil
			players << Player.new(init.challenger, 'X')
		end
		if init.interactif == 1 && init.player != nil
			puts "#{$0}: Wrong given arguments"
			init.help
			exit 42
		end

		init.version

		i = 0
		for player in players
			player.launch
			i = i + 1
			player.write_to_player("$$$ exec p#{i} : [#{player.file_name}]\n")

			if (init.verbose > 0)
				puts "$$$ exec p#{i} : [#{player.file_name}]\n"
			end
		end

		if init.interactif && players[0].nil?
			players << Player.new(init.player, 'O')
			players[0].mode_interactive
		end


		if (init.verbose > 0)
			map.show_mapcontent($stdout)
		end

		while all_lose(players, trace)
			for player in players
				if (player.live > 0)
					map.gene_piece()
                                  begin
					if init.interactif == 0
						map.show_mapcontent(player.stdin)
					end
					map.show_piececontent(player.stdin)

					if (init.verbose > 0 && init.interactif == 0)
						map.show_piececontent($stdout)
					end
                                  rescue
                                    player.end_player(trace)
                                  end
					begin
						player_time = Timeout::timeout(init.time) do
							@line = player.read_from_player()
						end
					rescue Timeout::Error
						puts "Player with #{player.piece_char}: timedout"
						trace.trace_msg "#{player.piece_char}: timedout\n"
						player.end_player trace
					end
					if (player.live > 0 && (nb = @line.gsub(/\s+/m, ' ').strip.split(" ")).length != 2)
						puts "Player with #{player.piece_char}: error on input"
						trace.trace_msg "#{player.piece_char}: error on input\n"
						player.end_player trace
					end

					if (player.live > 0 && init.verbose > 0)
						puts "<got (#{player.piece_char}): [#{nb[0]}, #{nb[1]}]"
					end

					if (player.live > 0 && map.check_placement(nb[0].to_i, nb[1].to_i, player.piece_char) == 1)
						map.change_data(nb[0].to_i, nb[1].to_i, player.piece_char)
						player.score += 1
					else
						player.end_player trace
					end

					if (init.verbose > 0 && player.live > 0)
						map.show_mapcontent($stdout, player.piece_char.downcase, nb[0].to_i, nb[1].to_i)
					end
				end
			end
		end

		for player in players
		player.score_show()
		end

		trace.the_end players
		if init.challenger != nil
			if (players[0].score < players[1].score)
				exit 2
			elsif (players[1].score < players[0].score)
				exit 1
			end
		end
		exit 0
	 rescue
	 	puts "An error occured. aborting..."
	 	exit -42
	 end
end
