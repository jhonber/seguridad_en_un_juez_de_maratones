require 'socket'
require 'httparty'
require 'json'

class SConsumer
  include HTTParty
  format :json
  
  def initialize(user, pass)
    @auth = {:username => user, :password => pass}
  end

  def get(ur,d)
    options = { :query => d, :basic_auth => @auth }
    self.class.get(ur,options)
  end

end


class RVeredict

  def initialize(ip,port,user,pass,id)
    @base_uri = 'http://' + ip + ':' + port
    @user = user
    @pass = pass
    @id = id
  end

  def run_rv()
    ur = "#{@base_uri}/submissions/#{@id}/update_veredict.json"
    d = { :veredict => "YES", :time => "0.0" }
    response = SConsumer.new(@user,@pass).get(ur,d)
  end
end

ip =   "#{ARGV[0]}"
port = "#{ARGV[1]}"
user = "#{ARGV[2]}"
pass = "#{ARGV[3]}"
id =   "#{ARGV[4]}"

rv = RVeredict.new(ip,port,user,pass,id)
rv.run_rv
